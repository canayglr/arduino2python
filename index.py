import serial

# Seri portu aç ve baud hızını ayarla
ser = serial.Serial('COM6', 9600)
cluster = ""
while True:
    if ser.in_waiting > 0:  # Gelen veri varsa
        line = ser.readline().decode('utf-8').rstrip()  # Veriyi oku, kod çöz ve boşlukları sil
        try:
            sayi = int(line)  # Veriyi tam sayıya çevir
            print(sayi)  # Tam sayıyı yazdır
        except ValueError:
            print("Geçersiz veri alındı.")  # Tam sayıya dönüştürülemeyen veri için hata mesajı
