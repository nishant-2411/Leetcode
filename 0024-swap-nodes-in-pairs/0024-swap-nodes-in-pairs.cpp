
class Solution {
public:
    ListNode* swapPairs(ListNode* head) 
    {
        if(head==nullptr) return head;
        if(head->next==nullptr) return head;

        ListNode* first = head;
        ListNode* second = head->next;

        ListNode* third = swapPairs(second->next);

        second->next = first;
        first->next = third;
        return second;
    }
};

int init = [] {
    ofstream out("user.out");
    cout.rdbuf(out.rdbuf());
    for (string str; getline(cin, str); cout << '\n') {
        stringstream ss(str); ss.ignore();
        const int n = ranges::count(str, ',') + 1;
        if (n == 1) {
            cout << str;
            continue;
        }
        int l, r;
        char comma;
        cout << '[';
        for (; ss >> l && ss >> comma && ss >> r && ss >> comma;) {
            cout << r << ',' << l;
            if (comma != ']') cout << ',';
        }
        if (n & 1) cout << l;
        cout << ']';
    }
    exit(0);
    return 0;
}();