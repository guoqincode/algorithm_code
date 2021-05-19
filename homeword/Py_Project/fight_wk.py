import  string
from itertools import  cycle
import numpy as np
import re
import itertools
from itertools import combinations
from itertools import product
mi="Ppqca xqvekg ybnkmazu ybngbal jon i tszm jyim. Vrag voht vrau c tksg. Ddwuo xitlazu vavv raz c vkb qp iwpou."
message="Ppqca xqvekg ybnkmazu ybngbal jon i tszm jyim. Vrag voht vrau c tksg. Ddwuo xitlazu vavv raz c vkb qp iwpou."

Key="PIZZA"
cipher="Adiz Avtzqeci Tmzubb wsa m Pmilqev halpqavtakuoi, lgouqdaf, kdmktsvmztsl, izr xoexghzr kkusitaaf. Vz wsa twbhdg ubalmmzhdad qz hce vmhsgohuqbo ox kaakulmd gxiwvos, krgdurdny i rcmmstugvtawz ca tzm ocicwxfg jf stscmilpy oid uwydptsbuci wabt hce Lcdwig eiovdnw. Bgfdny qe kddwtk qjnkqpsmev ba pz tzm roohwz at xoexghzr kkusicw izr vrlqrwxist uboedtuuznum. Pimifo Icmlv Emf DI, Lcdwig owdyzd xwd hce Ywhsmnemzh Xovm mby Cqxtsm Supacg (GUKE) oo Bdmfqclwg Bomk, Tzuhvif'a ocyetzqofifo ositjm. Rcm a lqys ce oie vzav wr Vpt 8, lpq gzclqab mekxabnittq tjr Ymdavn fihog cjgbhvnstkgds. Zm psqikmp o iuejqf jf lmoviiicqg aoj jdsvkavs Uzreiz qdpzmdg, dnutgrdny bts helpar jf lpq pjmtm, mb zlwkffjmwktoiiuix avczqzs ohsb ocplv nuby swbfwigk naf ohw Mzwbms umqcifm. Mtoej bts raj pq kjrcmp oo tzm Zooigvmz Khqauqvl Dincmalwdm, rhwzq vz cjmmhzd gvq ca tzm rwmsl lqgdgfa rcm a kbafzd-hzaumae kaakulmd, hce SKQ. Wi 1948 Tmzubb jgqzsy Msf Zsrmsv'e Qjmhcfwig Dincmalwdm vt Eizqcekbqf Pnadqfnilg, ivzrw pq onsaafsy if bts yenmxckmwvf ca tzm Yoiczmehzr uwydptwze oid tmoohe avfsmekbqr dn eifvzmsbuqvl tqazjgq. Pq kmolm m dvpwz ab ohw ktshiuix pvsaa at hojxtcbefmewn, afl bfzdakfsy okkuzgalqzu xhwuuqvl jmmqoigve gpcz ie hce Tmxcpsgd-Lvvbgbubnkq zqoxtawz, kciup isme xqdgo otaqfqev qz hce 1960k. Bgfdny'a tchokmjivlabk fzsmtfsy if i ofdmavmz krgaqqptawz wi 1952, wzmz vjmgaqlpad iohn wwzq goidt uzgeyix wi tzm Gbdtwl Wwigvwy. Vz aukqdoev bdsvtemzh rilp rshadm tcmmgvqg (xhwuuqvl uiehmalqab) vs sv mzoejvmhdvw ba dmikwz. Hpravs rdev qz 1954, xpsl whsm tow iszkk jqtjrw pug 42id tqdhcdsg, rfjm ugmbddw xawnofqzu. Vn avcizsl lqhzreqzsy tzif vds vmmhc wsa eidcalq; vds ewfvzr svp gjmw wfvzrk jqzdenmp vds vmmhc wsa mqxivmzhvl. Gv 10 Esktwunsm 2009, fgtxcrifo mb Dnlmdbzt uiydviyv, Nfdtaat Dmiem Ywiikbqf Bojlab Wrgez avdw iz cafakuog pmjxwx ahwxcby gv nscadn at ohw Jdwoikp scqejvysit xwd hce sxboglavs kvy zm ion tjmmhzd. Sa at Haq 2012 i bfdvsbq azmtmd'g widt ion bwnafz tzm Tcpsw wr Zjrva ivdcz eaigd yzmbo Tmzubb a kbmhptgzk dvrvwz wa efiohzd."


length = len(cipher)
flag = np.zeros(length)
for i in range(len(cipher)):
    if (cipher[i] >= 'A' and cipher[i] <= 'Z'):
        flag[i] = 1


def encrypt(message,Key):
    message = message.lower()
    Key = Key.lower()
    sum1=0
    mi = ""
    for i in range(len(message)):
        if (message[i] >= 'a' and message[i] <= 'z'):
            if (flag[i] == 1):
                temp = (ord(message[i]) + ord(Key[sum1]) - 2 * 97) % 26
                mi = mi + chr(temp + 97 - 32)
                sum1 = (sum1 + 1) % len(Key)
            else:
                temp = (ord(message[i]) + ord(Key[sum1]) - 2 * 97) % 26
                mi = mi + chr(temp + 97)
                sum1 = (sum1 + 1) % len(Key)
        else:
            mi = mi + message[i]
    return mi


def decrypt(mi,Key):
    sum1 = 0
    message=""
    mi = mi.lower()
    Key = Key.lower()
    for i in range(len(mi)):
        if (mi[i] >= 'a' and mi[i] <= 'z'):
            if (flag[i] == 1):
                temp = (ord(mi[i]) - ord(Key[sum1])) % 26
                message = message + chr(temp + 97 - 32)
                sum1 = (sum1 + 1) % len(Key)
            else:
                temp = (ord(mi[i]) - ord(Key[sum1]) ) % 26
                message = message + chr(temp + 97)
                sum1 = (sum1 + 1) % len(Key)
        else:
            message = message + mi[i]
    return  message


def get_spilt_mi(mi):
    mi = mi.upper()
    spilt_mi = ""
    for i in range(len(mi)):
        if (mi[i] >= 'A' and mi[i] <= 'Z'):
            spilt_mi = spilt_mi + mi[i]
    return  spilt_mi


def find_all(sub, s):
    index_list = []
    index = s.find(sub)
    while index != -1:
        index_list.append(index)
        index = s.find(sub, index + 1)

    if len(index_list) > 0:
        return index_list
    else:
        return -1

def find_repeat_sequences_spacings(spilt_mi):
    dict = {}
    submi = ""
    for i in range(3, 6):
        for j in range(len(spilt_mi)):
            submi = spilt_mi[j:j + i]
            index_list = find_all(submi, spilt_mi)
            if (len(submi) == i and dict.__contains__(submi) == False and len(index_list) > 1):
                location = []
                for l in range(len(index_list)):
                    for w in range(l + 1, len(index_list)):
                        location.append(index_list[w] - index_list[l])
                dict[submi] = location
    return dict


#求因子
def get_useful_factors(n):
    if n == 0: return [0]
    if n == 1: return [1]
    rlist = []
    for i in range(1,n+1):
        if n%i == 0:
            rlist.append(i)

    return rlist

def find_key_length(dict):
    key_length=[]
    for key in dict:
        location=dict[key]
        for i in range(len(location)):
            rlist=get_useful_factors(location[i])
            key_length=key_length+rlist
    return  key_length

def all_list(arr):
    result = {}
    for i in set(arr):
        result[i] = arr.count(i)
    return result
def get_key_list(dict):
    key_length=find_key_length(dict)
    result = all_list(key_length)
    result.pop(1)

    result = sorted(result.items(), key=lambda x: x[1], reverse=True)
    key_list=[]
    for i in range(len(result)):
        key_list.append(result[i][0])

    return  key_list


def get_nth_subkeys_letters(n,key_length,spilt_mi):
    result=""
    for i in range(0,len(spilt_mi),key_length):
        if(i+n-1<=(len(spilt_mi)-1)):
            result = result + spilt_mi[i + n - 1]

    return  result

# for i in range(1,5):
#     print(get_nth_subkeys_letters(i, 4, spilt_mi))

#我们假设密钥长度为4

#def freq_match_score(spilt_mi):
#统计字母频率
def strcount(a):
    #定义一个空字典
    b={}
    # 求出字符串的长度
    c=len(a)
    i=0
    while i<c:
        if a[i] in b:
            b[a[i]]+=1
        else:
            b[a[i]]=1
        i+=1
    #遍历字典
    return b
def freq_match_score(spilt_mi):
    ETAOIN = "ETAOINSHRDLCUMWFGYPBVKJXQZ"
    match_score = 0
    freq1 = strcount(spilt_mi)

    freq2 = {}

    freq1 = sorted(freq1.items(), key=lambda x: x[1], reverse=True)
    #print(freq1)
    for i in range(len(freq1)):
        if freq1[i][1] not in freq2.keys():
            list1 = [freq1[i][0]]
            temp = {freq1[i][1]: list1}
            freq2.update(temp)
        else:
            freq2[freq1[i][1]].append(freq1[i][0])
   # print(freq2)
    # office_freq
    zimu = []
    zimubiao = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    for key1 in freq2:
        freq2[key1].sort(key=ETAOIN.find, reverse=True)
        zimu = zimu + freq2[key1]
    appear = np.ones(26)
    for i in range(len(zimubiao)):
        if (zimubiao[i] not in zimu):
            appear[i] = 0
    rest = []

    for i in range(len(zimubiao)):
        if appear[i] == 0:
            temp = chr(i + 65)
            rest.append(temp)
    if(len(rest)==0):
        zimu.sort(key=ETAOIN.find, reverse=True)
    else:
        rest.sort(key=ETAOIN.find, reverse=True)
        zimu = zimu + rest



    score = 0
    # 分别取前六个和后六个
    front = ETAOIN[0:6]
    back = ETAOIN[-6:]

    for i in range(6):
        if (zimu[i] in front):
            score = score + 1
    for i in range(20, 26):
        if (zimu[i] in back):
            score = score + 1
    return score

def is_english(mi,word_percentage=20,letter_percentage=85):
    with open("D:\\code\\Py_Project\\homework\\dictionary.txt", "r") as f:
        dictionary = f.read().splitlines()  # 获取 文件全部数据 不要回车, 返回结果是一个列表
    mi = mi.upper()
    pat = '[a-zA-Z]+'
    lst = re.findall(pat, mi)
    W = 0
    M = len(lst)
    for i in range(M):
        if lst[i] in dictionary:
            W=W+1
    word=(W/M)*100
    L=0
    C=len(mi)
    for i in range(C):
        if(mi[i] >='A' and mi[i] <='Z'):
            L=L+1
        if(mi[i]==" "):
            L=L+1
    letter=(L/C)*100
    if(word>=word_percentage and letter>=letter_percentage):
        flag=True
    else:
        flag=False
    return  flag

# #首先对密文进行处理
# spilt_mi=get_spilt_mi(mi)
# print(spilt_mi)
# #打印列表
# dict=find_repeat_sequences_spacings(spilt_mi)
# print(dict)
# #获取可能的密钥长度
# key_list=get_key_list(dict)
# print(key_list)
zimu="ABCDEFGHIJKLMNOPQRSTUVWXYZ"

#l1=list(itertools.permutations(zimu,5))
score=0
key={}
for i in range(len(zimu)):
    message=decrypt("PXKNZNLIMMGTUSWIZVZBW",zimu[i])
    message=message.upper()
    fsocre=freq_match_score(message)
    temp={zimu[i]:fsocre}
    key.update(temp)

key = sorted(key.items(), key=lambda x: x[1], reverse=True)









spilt_cipher=get_spilt_mi(cipher)
print(spilt_cipher)
dict=find_repeat_sequences_spacings(spilt_cipher)
print(dict)
#获取可能的密钥长度
key_list=get_key_list(dict)
print(key_list)
flag1=0
for i in range(len(key_list)):
    if flag1==1:
        break
    print(key_list[i])
    possile_key = []
    for j in range(1, key_list[i] + 1):
        series = get_nth_subkeys_letters(j, key_list[i], spilt_cipher)
        key = {}
        son_key = ""
        for k in range(len(zimu)):
            message = decrypt(series, zimu[k])
            message = message.upper()
            fsocre = freq_match_score(message)
            temp = {zimu[k]: fsocre}
            key.update(temp)
            key_sort = sorted(key.items(), key=lambda x: x[1], reverse=True)
        for m in range(key_list[i]):
            son_key = son_key + key_sort[m][0]
        # 获取列表
        possile_key.append(son_key)
    key_com = []
    for l in product(*possile_key):
        key_com.append(l)
    # ss1=''.join(key_com[0])
    # 开始遍历所有的组合判断是否符合条件
    for y in range(len(key_com)):
        p_key = ''.join(key_com[y])
        de = decrypt(cipher, p_key)
        if (is_english(de)):
            print("破解后的密文为:")
            print(de)
            with open("result.txt", "w", encoding='utf-8') as f:
                f.write(de)
                f.close()
            print("密钥为:")
            print(p_key)
            flag1=1
            break































