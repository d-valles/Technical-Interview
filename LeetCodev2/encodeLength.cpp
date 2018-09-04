string encode(string source) {
        string dest;
        for (int i = 0; i < (int)source.size(); i++) {
            int runLength = 1;
            while(i < source.size() - 1 && source[i] == source[i + 1])
            {
                runLength++;
                i++;
            }
            dest += source[i];
            dest += intToString(runLength);
          
        }
        return dest;
}