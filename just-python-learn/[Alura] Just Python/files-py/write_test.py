contacts_file = open('font_files/contacts_write.csv', encoding='latin_1', mode='a+')

contacts = ['11, carol, carol@carol.com.br\n',
            '12, ana, ana@ana.com.br\n',
            '13, amanda, amanda@amanda.com.br\n',
            '14, igor, igor@igor.com.br\n']

for contact in contacts:
    contacts_file.write(contact)

contacts_file.flush()

# Modificando linha da ana e percorrendo no arquivo
contacts_file.seek(28)
contacts_file.write('12, Ana, ana@ana.com.br\n'.upper())
contacts_file.flush()
contacts_file.seek(0)

for line in contacts_file:
    print(line)
    


