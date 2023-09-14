texto = input("texto: ")

letra = 0
palavras = 1
sentenca = 0


for palavra in texto:
    if palavra.isalpha():
        letra += 1
    elif palavra.isspace():
        palavras += 1
    elif palavra in ('!', '?', '.'):
        sentenca += 1

letra = (letra / palavras * 100) * 0.0588
sentenca = (sentenca / palavras * 100) * 0.296
grade = int((letra - sentenca + 0.5) - 15.8)

if grade <= 1:
    print("Before Grade 1")
elif grade > 1 and grade < 16:
    print(f"Grade {grade}")
else:
    print("Grade 16+")