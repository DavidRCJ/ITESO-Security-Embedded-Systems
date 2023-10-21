#Correr en copilador ONLINE

from cryptography.fernet import Fernet
# Genera una clave de cifrado aleatoria
key = Fernet.generate_key()
# Crea un objeto Fernet con la clave generada
fernet = Fernet(key)
# Texto que quieres cifrar
texto_original = "Las mañanas lluviosas son geniales"
#texto_original = "Hola soy David y esta es la tarea de Cifrado utilizando AES"
# Convierte el texto a bytes (UTF-8)
texto_original_bytes = texto_original.encode("utf-8")
# Cifra el texto
texto_cifrado = fernet.encrypt(texto_original_bytes)
# Imprime el texto cifrado
print("Texto cifrado:", texto_cifrado)
# Descifra el texto
texto_descifrado_bytes = fernet.decrypt(texto_cifrado)
# Convierte los bytes de vuelta a texto
texto_descifrado = texto_descifrado_bytes.decode("utf-8")
# Imprime el texto descifrado
print("Texto descifrado:", texto_descifrado)