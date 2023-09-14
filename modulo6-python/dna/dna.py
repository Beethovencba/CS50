import sys
import csv

if len(sys.argv) != 3:
    sys.exit("Usage: python dna.py data.csv sequence.txt")

csv_data = {}
try:
    with open(sys.argv[1], "r") as arquivo:
        reader = csv.DictReader(arquivo)

        for row in reader:
            name = row['name']
            csv_data[name] = {col: int(value) for col, value in row.items() if col != 'name'}

    with open(sys.argv[2], "r") as sequencia:
        sequence = sequencia.read()

except FileNotFoundError:
    sys.exit("Usage: python dna.py data.csv sequence.txt")

substrings = {'AGATC', 'TTTTTTCT', 'AATG', 'TCTAG', 'GATA', 'TATC', 'GAAA', 'TCTG'}
found_substrings = {}

# Loop para encontrar todas as ocorrências das substrings
for substring in substrings:
    max_count = 0
    current_count = 0
    i = 0
    while i < len(sequence) - len(substring) + 1:
        if sequence[i:i+len(substring)].upper().strip() == substring:
            current_count += 1
            max_count = max(max_count, current_count)
            i += len(substring)
        else:
            current_count = 0
            i += 1
    found_substrings[substring] = max_count

name_found = False

for name, values in csv_data.items():
    x = 0
    for substring, count in found_substrings.items():
        if values.get(substring) == count:
            x += 1

    if x == 8:
        name_found = True
        break

if name_found:
    print(name)
else:
    print('No match')