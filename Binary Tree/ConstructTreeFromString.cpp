Node*solve(string s,int &i){
    string str="";
    if(i>=s.length()){
        return NULL;
    }
    int ele=0;
     Node*ans=NULL;
    while(s[i]>='0' && s[i]<='9'){
        ele=ele*10+s[i]-'0';
         ans= new Node(ele);
        i++;
    }
    
      if(s[i]=='('){
        i++;
        ans->left=solve(s,i);
    }
      
      if(s[i]=='('){
        i++;
        ans->right=solve(s,i);
    }
    
    if(s[i]==')'){
        i++;
        return ans;
    }
    
   
   i++;
   return ans;
 
}
    Node *treeFromString(string str){
        // code here
        int ind = 0;
        return solve(str, ind);
    }
