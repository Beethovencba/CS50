while True:
    try:
        troco = float(input("Insira o troco a receber: R$ "))

        if troco > 0.00:
            break
        else:
            print("Insira valor valido maior que 0!")

    except ValueError:
        print("Digite um valor numérico válido.")

i = 0
troco = (troco * 100) + 0.5

while troco > 0.5:
    if troco >= 25:
        troco = troco - 25
    elif troco >= 10:
        troco = troco - 10
    elif troco >= 5:
        troco = troco - 5
    elif troco >= 1:
        troco = troco - 1
    i += 1

print(i)

