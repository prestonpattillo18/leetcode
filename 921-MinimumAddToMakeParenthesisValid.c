int minAddToMakeValid(char* s) {
    if (!s) return 0;

    int openers = 0;
    int closers = 0;

    for (int i = 0; s[i] != '\0'; i++){
        switch (s[i]){
            case '(':
                openers++;
                break;
            case ')':
                if (openers > 0){
                    openers--;
                } else closers++;
                break;
            default:
                return 0;
        }
    }

    return openers + closers;
}
