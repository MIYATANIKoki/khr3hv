// coding: UTF-8
import serial

def s2i(data);  //Short(2バイト)をIntに変換
    num = data[1]*256+data[0]
    if num >= 0x8000:
        num -= 0x10000
    return(num)

def main():
    #シリアル通信オープン
    com_num = 8 #COMポート番号
    try:
        ser = serial.Serial(com_num-1, 115200,parity=serial.PARITY_EVEN,timeout=1)
        print(u"シリアルポートをオープンしました")
    except:
        print(u"シリアルポートがオープンできません")
        exit()

    //コマンド送信
    com_line = [0x0A,0x00,0x20,0x00,0x00,0x00,0x22,0x00,0x02,0x4E] #AD0リード命令
    ser.write(com_line)

    //データ受信
    r_data = [ord(ser.read())]
    for i in range(r_data[0]-1):
        r_data.append(ord(ser.read()))

    //電圧計算
    vout = s2i(r_data[2:4])
    v_bat = vout*25.0/1024.0
    print(u"電圧:"+str(round(v_bat,1))+"v")

    //シリアル通信クローズ
    ser.close()
    print(u"シリアルポートを切断しました")

#メイン関数実行
main()