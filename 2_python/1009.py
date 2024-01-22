for _ in range(int(input())):
    a, b = map(int, input().split())
    answer = a
    for _ in range(1, b):
        answer = (answer * a) % 10
    print(answer % 10 if answer % 10 else 10)