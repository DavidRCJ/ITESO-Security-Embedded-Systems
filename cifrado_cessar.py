#David Ricardo Cruz Juarez
#Caesar Cipher - www.101computing.net/caesar-cipher
#cipher = "N qtaj uwtlwfrrnsl zxnsl Udymts"
#Complete the code below to decode this cipher using a 5-character right shift

def cesar_espanol(cipher):
    resultado = ""
    for caracter in cipher:
        if caracter.isalpha():
            mayuscula = caracter.isupper()
            caracter = caracter.upper()
            codigo = ord(caracter) - ord('A')
            codigo = (codigo - 5) % 26  # Usamos 26 para no incluir la letra "Ñ", dado que el cifrado esta en ingles
            caracter_descifrado = chr(codigo + ord('A'))
            if not mayuscula:
                caracter_descifrado = caracter_descifrado.lower()
            resultado += caracter_descifrado
        else:
            resultado += caracter
    return resultado

# Ejemplo de uso
cipher  = "N qtaj uwtlwfrrnsl zxnsl Udymts"
texto_descifrado = cesar_espanol(cipher)
print("Texto descifrado:", texto_descifrado)
