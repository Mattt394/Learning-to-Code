# CRACK
#Implement a program that cracks passwords

import crypt


# crypt.crypt(word, salt)

def main():
    salt = "50"

    hashp = input("Give me a hash: ")
    #Test the hash
    #print(crypt.crypt('ZZ', '50'))

    letters = []
    for i in range(26):
        letters.append(ord('a') + i)
    for i in range(26, 52):
        letters.append(ord('A') + i-26)

    for word in ('a', 'aa', 'aaa', 'aaaa'):
        if cycle(word, hashp, letters, salt):
            return

#def cycle(word, hashp):
#    word = ord(word)-1
#    while (word < (word+26)):
#        word = chr(word)
#        if (crypt.crypt(word, salt) == hashp):
#            print(word)
#            return True
#        word = ord(word)
#    return False

def cycle(word, hashp, letters, salt):
    words = []
    for i in range(len(word)):
        words.append(word[i])

    ii = 0

    while (ii<52):
        if (len(word)>1):
            jj=0
            while (jj<52):
                if (len(word)>2):
                    kk=0
                    while (kk<52):
                        if (len(word)>3):
                            ll=0
                            while (ll<52):
                                words[0] = chr(letters[ii])
                                words[1] = chr(letters[jj])
                                words[2] = chr(letters[kk])
                                words[3] = chr(letters[ll])
                                s = ''.join(words)
                                if (crypt.crypt(s, salt) == hashp):
                                    print(s)
                                    return True
                                ll += 1
                            kk += 1

                        else:
                            words[0] = chr(letters[ii])
                            words[1] = chr(letters[jj])
                            words[2] = chr(letters[kk])
                            s = ''.join(words)
                            if (crypt.crypt(s, salt) == hashp):
                                print(s)
                                return True
                            kk += 1
                    jj += 1

                else:
                    words[0] = chr(letters[ii])
                    words[1] = chr(letters[jj])
                    s = ''.join(words)
                    if (crypt.crypt(s, salt) == hashp):
                        print(s)
                        return True
                    jj += 1
            ii += 1

        else:
            words[0] = chr(letters[ii])
            s = ''.join(words)
            if (crypt.crypt(s, salt) == hashp):
                print(s)
                return True
            ii += 1
    return False


if __name__ == "__main__":
    main()
