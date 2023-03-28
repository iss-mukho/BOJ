# 백준 10820: 문자열 분석(브론즈 II), https://www.acmicpc.net/problem/10820
while True:
    try:
        inputString = input()

        lowerCount = 0
        upperCount = 0
        numberCount = 0
        spaceCount = 0

        for s in inputString:
            if 'a' <= s <= 'z':
                lowerCount += 1
                continue
            if 'A' <= s <= 'Z':
                upperCount += 1
                continue
            if '0' <= s <= '9':
                numberCount += 1
                continue
            if s == ' ':
                spaceCount += 1
                continue
        
        print(f"{lowerCount} {upperCount} {numberCount} {spaceCount}")
    except:
        break
