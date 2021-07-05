outStr = "HE GOT AWAY!"
for i in range(5):
    if i == 5:
        print("HE GOT AWAY!")
    else:
        inStr = input()
        if inStr.find("FBI") != -1:
            if outStr == "HE GOT AWAY!":
                outStr = str(i+1)
            else:
                outStr += ' ' + str(i+1)
print(outStr)