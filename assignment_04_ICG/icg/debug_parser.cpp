#include <bits/stdc++.h>
using namespace std;

string trim(const string &s) {
    auto a = s.find_first_not_of(" \t");
    if (a == string::npos) return "";
    auto b = s.find_last_not_of(" \t");
    return s.substr(a, b - a + 1);
}

bool parse_instruction(const string &line, string &op, vector<string> &operands) {
    operands.clear();
    string t = trim(line);
    
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
    string line = "ADD AX, 0";
    string op;
    vector<string> operands;
    
    cout << "Testing line: '" << line << "'" << endl;
    
    if (parse_instruction(line, op, operands)) {
        cout << "Operation: '" << op << "'" << endl;
        cout << "Operands count: " << operands.size() << endl;
        for (int i = 0; i < operands.size(); i++) {
            cout << "Operand " << i << ": '" << operands[i] << "'" << endl;
        }
        
        if (operands.size() == 2) {
            cout << "Checking condition: op='" << op << "', operand1='" << operands[1] << "'" << endl;
            if ((op == "ADD" || op == "SUB") && operands[1] == "0") {
                cout << "SHOULD BE REMOVED!" << endl;
            } else {
                cout << "Not matching removal condition" << endl;
            }
        }
    }
    
    return 0;
}
