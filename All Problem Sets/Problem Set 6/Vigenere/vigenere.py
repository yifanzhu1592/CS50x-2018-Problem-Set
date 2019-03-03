from cs50 import get_string
from sys import argv


def main():

    k = argv[1] # get the key
    counter = 0

    if len(argv) != 2:
        print("Error.")
        exit(1)
    else:
        for j in range(len(k)):
            if k[j].isalpha():
                continue
            else:
                print("Error.")
                exit(1)
        print("Plaintext: ", end = "")
        p = get_string() # get the plaintext
        #encipher
        answer = ""
        for i in range(len(p)):
            if p[i].isalpha():
                if k[(i - counter) % len(k)].isupper():
                    if p[i].isupper():
                        answer += chr((ord(p[i]) + ord(k[(i - counter) % len(k)]) - ord('A') - ord('A')) % 26 + ord('A'))
                    else:
                        answer += chr((ord(p[i]) + ord(k[(i - counter) % len(k)]) - ord('A') - ord('a')) % 26 + ord('a'))
                else:
                    if p[i].isupper():
                        answer += chr((ord(p[i]) + ord(k[(i - counter) % len(k)]) - ord('a') - ord('A')) % 26 + ord('A'))
                    else:
                        answer += chr((ord(p[i]) + ord(k[(i - counter) % len(k)]) - ord('a') - ord('a')) % 26 + ord('a'))
            else:
                counter += 1
                answer += p[i]

    print("ciphertext: ", end = "")
    print(answer)

if __name__ == "__main__":
    main()
