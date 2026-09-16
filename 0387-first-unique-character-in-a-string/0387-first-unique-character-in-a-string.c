int firstUniqChar(char* s) {
    int i = 0, map[26], sSize = strlen(s);

    for(int i =0; i <26; i++){
        map[i] = 0;
    }

    for(int i = 0; i < sSize; i++){
        map[s[i] - 'a']++;
    }

    for(int i = 0; i<sSize; i++){
        if(map[s[i] - 'a'] == 1)
        return i;
    }

    return -1;
}