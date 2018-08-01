// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int total = 0;
        bool eof = false;
        
        while (!eof && total < n) {
            int total4 = read4(buf);
            
            if (total4 < 4) {
                eof = true;
            }
            
            for (int i = 0; i < total4; i++) {
                buf += 1;
            }
            
            total += total4;
        }
        
        return total >= n ? n : total;
    }
};