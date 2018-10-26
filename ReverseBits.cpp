unsigned int Solution::reverse(unsigned int A)
{
    int i;
    unsigned int b=0;
    int bit=0;
    for(i=0;i<32;i++)
    {
        //cout<<A<<" "<<b<<endl;
        bit=A & 1;
        b=b | bit;
        A=A>>1;
        if(i!=31)
        b=b<<1;
    }
    return b;
}
