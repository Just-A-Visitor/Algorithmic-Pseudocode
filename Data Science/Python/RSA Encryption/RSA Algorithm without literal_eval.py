# Acknowledgement : Idea Inspired By
# https://stackoverflow.com/questions/21327491/using-pycrypto-how-to-import-a-rsa-public-key-and-use-it-to-encrypt-a-string

#
# str ==> encode() ==> bytes
# bytes ==> decode() ==> str
#



# Import the required libraries
import Crypto
from Crypto.PublicKey import RSA
from Crypto.Cipher import PKCS1_OAEP

# Take the message as input
original_message = input("Please enter the message to be encrypted: ")

# Take the bit size of the key as 2048
bit_length = 2048

# Create a key object containing all the variables and method of RSA
key_object = RSA.generate(bit_length)

# Extract the private and public key in binary format
binary_Private_Key = key_object.exportKey('DER')
binary_Public_Key = key_object.publickey().exportKey('DER')

# Import the public_key and private_key to decrypt it later
private_key = RSA.importKey(binary_Private_Key)
public_key = RSA.importKey(binary_Public_Key)

# Create a cipher in string format 
cipher = PKCS1_OAEP.new(public_key)
# Encryption can only be done on bytes format
encrypted_message = cipher.encrypt(original_message.encode())

# The encrypted message is also in bytes format
# print(encrypted_message)
# print()


# Write the encrypted message to a file. Remember to write bytes
file = open('encrypted_file.txt','wb')
file.write(encrypted_message)
file.close()


# Read the encrypted message again. Remember to read bytes
file = open('encrypted_file.txt','rb')
encrypted_message = file.read()
file.close()


# Create a new cipher with private key
cipher = PKCS1_OAEP.new(private_key)

# The message is already in bytes format, so just decrypt it
decrypted_message = cipher.decrypt(encrypted_message)
# Note that the decrypted message is also in bytes format


# Encryption and decryption can only be done in bytes format


# Let us print the encrypted message again
print("------------------------------")
#print(encrypted_message)


# Write the original message and the decrypted message to the file to see if they are the same or not
# decrypted_message is in bytes format, convert it to string format
file = open('result.txt','w')
file.write(original_message)
file.write('\n')
file.write(decrypted_message.decode())
file.close()

# Read the file again to see if the messages are same or not
file = open('result.txt','r')
displayed_message = file.read()
file.close()

# Print the message to compare the output
print(displayed_message)
