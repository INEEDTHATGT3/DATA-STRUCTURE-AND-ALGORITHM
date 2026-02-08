bool isPalindrome(string& s, int start, int end){
    // base case
    if(start >= end){
        return true;
    }
    //one case solution
    if(s[start] != s[end]){
        return false;
    }
    // recursion
    return isPalindrome(s, start+1, end-1);
}
int main(){
    string s;
    cin >> s;
    if(isPalindrome(s, 0, s.size()-1)){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}