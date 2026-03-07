#include <bits/stdc++.h>
using namespace std;

string trim(const string &s) {
    auto a = s.find_first_not_of(" \t\r\n");
    if (a == string::npos) return "";
    auto b = s.find_last_not_of(" \t\r\n");
    return s.substr(a, b - a + 1);
}

bool parse_instruction(const string &line, string &op, vector<string> &operands) {
    operands.clear();
    string t = trim(line);
    
    // Remove comment if present
    size_t comment_pos = t.find(';');
    if (comment_pos != string::npos) {
        t = t.substr(0, comment_pos);
        t = trim(t);
    }
    
    auto space = t.find(' ');
    if (space == string::npos) {
        op = t;
        return true;
    }
    
    op = t.substr(0, space);
    string rest = t.substr(space + 1);
    
    stringstream ss(rest);
    string operand;
    while (getline(ss, operand, ',')) {
        operands.push_back(trim(operand));
    }
    
    return true;
}

int main() {
    string line1 = "PUSH AX		; line 9";
    string line2 = "POP AX";
    
    string op1, op2;
    vector<string> operands1, operands2;
    
    cout << "Testing line1: '" << line1 << "'" << endl;
    cout << "Testing line2: '" << line2 << "'" << endl;
    
    if (parse_instruction(line1, op1, operands1)) {
        cout << "Line1 - Op: '" << op1 << "', Operands: ";
        for (const auto& op : operands1) cout << "'" << op << "' ";
        cout << endl;
    }
    
    if (parse_instruction(line2, op2, operands2)) {
        cout << "Line2 - Op: '" << op2 << "', Operands: ";
        for (const auto& op : operands2) cout << "'" << op << "' ";
        cout << endl;
    }
    
    bool should_remove = (op1 == "PUSH" && op2 == "POP" && operands1.size() == 1 && operands2.size() == 1 && operands1[0] == operands2[0]);
    cout << "Should remove: " << (should_remove ? "YES" : "NO") << endl;
    
    return 0;
}
