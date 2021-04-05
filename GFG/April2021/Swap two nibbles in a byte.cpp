class Solution{
public:
    int swapNibbles(unsigned char x){
        return ( (x & 0x0F) << 4 | (x & 0xF0) >> 4 );
    }
};