// O(n)
void manacher(string &st)
{
    string s;
    for(auto &ch: st){
        s.PB('#');
        s.PB(ch);
    }
    s.PB('#');
    int n=s.size();
    s="$"+s+"^";
    std::vector<int> p(n+2);
    int l=1,r=1; //s[l+1]...s[r-1] is the rightmost palindrome
    for(int i=1;i<=n;i++){
        if(r>=i)    p[i]=min(r-i,p[l+(r-i)]);
        while(s[i-p[i]]==s[i+p[i]]){
            p[i]++;
        }
        if((i+p[i])>r){
            l=i-p[i],r=i+p[i];
        }
    }
    for(int i=1;i<=n;i++)   p[i]--;
}
//relation with the actual 0 indexed string, st in respect to the vector, p
//p[i*2+1] is the lenth of the even palindromic sub-string where center is between st[i] and st[i-1]  
//p[i*2+2] is the lenth of the odd palindromic sub-string where center is st[i]
