while True:

    try:

        n = int(input("Height: "))

        if n > 0 and n <= 8:
            break
        else:
            print("Insira um numero de 1 a 8")
    except ValueError:
        print("Digite um valor numérico válido.")

for i in range(n):
    print(" " * ((n - 1) - i) + "#" * (i + 1) + " " + "#" * (i + 1))
