int Solution::isPalindrome(string A)
{
    string s=A;
    int j=A.size()-1;   //iterator to last element of string
    int i=0;            //iterator to first element of string
    while(j>i)
    {
        //condition to check for alphanumeric characters.
        //if s[i] is not a character or a number,
        // increment i and continue to the next char.
        if(!(s[i]>='a'&&s[i]<='z'||s[i]>='A'&&s[i]<='Z'||s[i]>='0'&&s[i]<='9'))
            {i++;continue;}
        if(!(s[j]>='a'&&s[j]<='z'||s[j]>='A'&&s[j]<='Z'||s[j]>='0'&&s[j]<='9'))
            {j--;continue;}
        //condition for matching of characters considering upper and lower case alphabets same.
        if(!(s[i]==s[j]||abs(s[i]-s[j])==32))
            return 0;

          i++;
          j--;
    }
    return 1;
}
