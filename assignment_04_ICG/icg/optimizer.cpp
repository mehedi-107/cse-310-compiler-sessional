#include <bits/stdc++.h>
using namespace std;

vector<string> code;
map<string,string> label_mapping;
vector<pair<string,string>> removed_lines;

string trim(const string &s){
    auto a = s.find_first_not_of(" \t\r\n");
    if (a == string::npos) return "";
    auto b = s.find_last_not_of(" \t\r\n");
    return s.substr(a,b-a+1);
}

bool is_label(const string &line){
    string t = trim(line);
    return !t.empty() && t.back() == ':';
}

bool is_empty_or_comment(const string &line){
    string t = trim(line);
    return t.empty() || t[0] == ';';
}
// split instruction into operation and operands
bool parse_instruction(const string &line, string &op, vector<string> &operands){
    operands.clear();
    string t = trim(line);
    // cout << "Parsing instruction: " << t << endl;
    // Remove comment if present
    size_t comment_pos = t.find(';');
    if (comment_pos != string::npos){
        t = t.substr(0, comment_pos);
        t = trim(t);
    }
    
    auto space = t.find(' ');
    if (space == string::npos){
        op = t;
        return true;
    }
    
    op = t.substr(0, space);
    string rest = t.substr(space + 1);
    // cout << "Operation: " << op << ", Rest: " << rest << endl;
    stringstream ss(rest);
    string operand;
    while (getline(ss, operand, ',')) {
        operands.push_back(trim(operand));
        // cout << "Found operand: " << operands.back() << endl;   
    }
    
    return true;
}

// Remove redundant MOV instructions
void remove_redundant_mov() {
    for (int i = 0; i < (int)code.size() - 1; i++) {
        string line1 = trim(code[i]);
        string line2 = trim(code[i + 1]);
        // cout << "Checking lines: " << line1 << " and " << line2 << endl;
        if (is_empty_or_comment(line1) || is_empty_or_comment(line2) || is_label(line1) || is_label(line2)) continue;
        string op1, op2;
        vector<string> operands1, operands2;
        if (parse_instruction(line1, op1, operands1) && parse_instruction(line2, op2, operands2) && op1 == "MOV" && op2 == "MOV" && operands1.size() == 2 && operands2.size() == 2 && operands1[0] == operands2[1] && operands1[1] == operands2[0]) {
            removed_lines.push_back({"Line " + to_string(i + 2) + ": Redundant MOV (MOV a, AX after MOV AX, a)", code[i + 1]});
            code.erase(code.begin() + i + 1);
            i--;
        }
    }
}

// Remove consecutive PUSH/POP of same register
void remove_consecutive_push_pop() {
    for (int i = 0; i < (int)code.size() - 1; i++) {
        string line1 = trim(code[i]);
        string line2 = trim(code[i + 1]);
        // cout << "Checking lines: " << line1 << " and " << line2 << endl;
        if (is_empty_or_comment(line1) || is_empty_or_comment(line2) || is_label(line1) || is_label(line2)) continue;
        string op1, op2;
        vector<string> operands1, operands2;
        if (parse_instruction(line1, op1, operands1) && parse_instruction(line2, op2, operands2) && op1 == "PUSH" && op2 == "POP" && operands1.size() == 1 && operands2.size() == 1 && operands1[0] == operands2[0]) {
            removed_lines.push_back({"Line " + to_string(i + 1) + ": Redundant consecutive PUSH/POP of same register", code[i]});
            removed_lines.push_back({"Line " + to_string(i + 2) + ": Redundant consecutive PUSH/POP of same register", code[i + 1]});
            code.erase(code.begin() + i, code.begin() + i + 2);
            i--;
        }
    }
}

// Remove redundant operations
void remove_redundant_operations(){
    for (int i = 0; i < (int)code.size(); i++) {
        string line = trim(code[i]);
        if (is_empty_or_comment(line) || is_label(line)) continue;
        string op;
        vector<string> operands;
        if (parse_instruction(line, op, operands) && operands.size() == 2) {
            bool should_remove = false;
            string reason;
            if ((op == "ADD" || op == "SUB") && operands[1] == "0") {
                should_remove = true;
                reason = op + " with 0 is redundant";
            } else if ((op == "MUL" || op == "DIV") && operands[1] == "1") {
                should_remove = true;
                reason = op + " with 1 is redundant";
            }
            else if ((op == "OR" || op == "XOR") && operands[1] == "0") {
                should_remove = true;
                reason = op + " with 0 is redundant";
            }
            if (should_remove) {
                removed_lines.push_back({"Line " + to_string(i + 1) + ": " + reason, code[i]});
                code.erase(code.begin() + i);
                i--;
            }
        }
    }
}

//Remove consecutive labels and update jumps
void remove_consecutive_labels(){
    label_mapping.clear();
    
    // Find consecutive labels
    for (int i = 0; i < (int)code.size(); i++){
        if (is_label(trim(code[i]))) {
            string first_label = trim(code[i]);
            first_label = first_label.substr(0, first_label.length() - 1); // remove ':'
            vector<string> consecutive_labels;
            consecutive_labels.push_back(first_label);
            // cout<< "Found label: " << first_label << " at line " << i + 1 << endl;
            // Find all consecutive labels
            int j = i + 1;
            while (j < (int)code.size()) {
                string line = trim(code[j]);
                if (is_label(line)) {
                    string label_name = line.substr(0, line.length() - 1);
                    removed_lines.push_back({"Line " + to_string(j + 1) + ": Redundant consecutive label (mapped to " + first_label + ")", code[j]});
                    consecutive_labels.push_back(label_name);
                    j++;
                } else if (is_empty_or_comment(line)) {
                    j++;
                } else {
                    break;
                }
            }
            
            // If multiple consecutive labels, map them to first and remove others
            if (consecutive_labels.size() > 1) {
                for (int k = 1; k < (int)consecutive_labels.size(); k++) {
                    label_mapping[consecutive_labels[k]] = first_label;
                    // cout << "Mapping label: " << consecutive_labels[k] << " to " << first_label << endl;
                }
                
                // Remove extra labels
                j = i + 1;
                while (j < (int)code.size()) {
                    string line = trim(code[j]);
                    if (is_label(line)) {
                        code.erase(code.begin() + j);
                    } else if (is_empty_or_comment(line)) {
                        j++;
                    } else {
                        break;
                    }
                }
            }
        }
    }
    
    // Update jump instructions
    for (int i = 0; i < (int)code.size(); i++) {
        string line = code[i];
        string t = trim(line);
        
        // Check for jump instructions
        vector<string> jump_ops = {"JMP", "JE", "JNE", "JL", "JLE", "JG", "JGE", "JZ", "JNZ"};
        
        for (const string& jop : jump_ops) {
            if (t.find(jop + " ") != string::npos) {
                size_t pos = t.find(jop + " ");
                size_t start = pos + jop.length() + 1;
                // cout<< "Found jump instruction: " << jop << " at line " << i + 1 << endl;
                size_t comment_pos = t.find(';', start);
                // cout<< "Processing jump instruction: " << jop << " at line " << i + 1 << endl;
                size_t end = (comment_pos != string::npos) ? comment_pos : t.length();
                string target = trim(t.substr(start, end - start));
                // cout<< "Jump target: " << target << endl;
                // Update if target is mapped
                if (label_mapping.find(target) != label_mapping.end()) {
                    string new_target = label_mapping[target];
                    size_t target_pos = line.find(target);
                    if (target_pos != string::npos) {
                        line = line.substr(0, target_pos) + new_target + line.substr(target_pos + target.length());
                        code[i] = line;
                    }
                }
                break;
            }
        }
    }
}

void generate_optimized_code(const string &input_file, const string &output_file, const string &log_file){
    code.clear();
    removed_lines.clear();
    
    ifstream infile(input_file);
    if (!infile.is_open()) {
        cerr << "Error opening input file: " << input_file << endl;
        return;
    }
    
    string line;
    while (getline(infile, line)) {
        code.push_back(line);
    }
    infile.close();
    
    cout << "Original code: " << code.size() << " lines" << endl;
    
    remove_redundant_mov();
    remove_consecutive_push_pop();
    remove_redundant_operations();
    remove_consecutive_labels();
    
    cout << "Optimized code: " << code.size() << " lines" << endl;
    
    ofstream outfile(output_file);
    if (!outfile.is_open()) {
        cerr << "Error opening output file: " << output_file << endl;
        return;
    }
    
    for (const auto &line : code) {
        outfile << line << endl;
    }
    outfile.close();
    
    // Write optimization log
    ofstream logf(log_file);
    if (!logf.is_open()) {
        cerr << "Error opening log file: " << log_file << endl;
        return;
    }
    
    for (const auto &entry : removed_lines) {
        logf << "[" << entry.first << "]\n" << entry.second << "\n\n";
    }
    logf.close();
    
    cout << "Optimization complete! Output written to: " << output_file << endl;
    cout << "Optimization log written to: " << log_file << endl;
}

// Main function for testing
// int main(int argc, char *argv[]) {
//     if (argc < 4) {
//         cerr << "Usage: " << argv[0] << " <input_filename> <output_filename> <log_filename>" << endl;
//         return 1;
//     }

//     string input_dir = "output/";
//     string input_file = input_dir + argv[1];
//     string output_file = input_dir + argv[2];
//     string log_file = input_dir + argv[3];

//     generate_optimized_code(input_file, output_file, log_file);
    
//     return 0;
// }
