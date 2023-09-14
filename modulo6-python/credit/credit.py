while True:
    try:
        cartao = int(input("insira o numero do cartão: "))
        digitos = str(cartao)
        if cartao > 0:
            break
        else:
            print("Insira valor valido maior que 0!")

    except ValueError:
        print("Digite um valor numérico válido.")

primeiro_dois_digitos = int(digitos[:2])
posicao_par = digitos[-2::-2]
posicao_impar = digitos[-1::-2]
multiplica = [int(digito) * 2 for digito in posicao_par]
lista_expandida = []

for numero in multiplica:
    for digito in str(numero):
        lista_expandida.append(int(digito))

total_par = sum(int(n) for n in lista_expandida)
total_impar = sum(int(digito) for digito in posicao_impar)
total = str(total_impar + total_par)

if int(total[1]) == 0:

    if primeiro_dois_digitos == 34 or primeiro_dois_digitos == 37:

        print("AMEX\n")

    elif primeiro_dois_digitos > 50 and primeiro_dois_digitos < 56:

        print("MASTERCARD\n")

    elif int(primeiro_dois_digitos / 10) == 4 and len(digitos) > 12:

        print("VISA\n")

    else:

        print("INVALID\n")


else:

    print("INVALID\n")
