# a=input().split()
# 他現在不是字串了 你注意他是甚麼類型
# 會變成一個陣列 陣列是啥不重要 你可以想成 他把它切成 "14" "15"兩個變數
'''
print(type(a))
print(a)
'''

#map的功能是把"14" "15"這兩個字串變數 轉成int 分配給很多個變數
'''
a,b=map(int,input().split())
print(type(a))
print(type(b))
print(a)
print(b)
'''
#所以這邊 split把 "14 15" 一個字串 切成 "14" "15"兩個字串
# map把 "14" "15"兩個字串轉成int然後分配給a,b
# 所以同一行輸入才要用map

#整理
# input()會輸入一整行 而且輸入進來是字串
# 所以 "14 15"會被當成一個字串 中間有空格沒辦法轉成int
#需要split()切成兩個字串 "14" "15"
#再用map轉成int然後分配給變數

#再來說f-string
#他是python 一個特殊的字串
#可以把變數塞進字串裡面
#像是這樣 f"我要輸出變數a的值是{a}"
#這樣第一個 a 會被當成字串 "a" 
#第二個 a 會被當成外面的變數 a
'''
a=int(input())
print(f"變數a是:{a}")
'''

#f-string還有控制小數位數的能力
#f"{a:.2f}"大括號包起變數 之後接 : 然後.2f表示輸出到小數第二位 .3f代表三位 以此類推
#然後他會四捨五入 a=1.235 f"{a:.2f}" 會輸出 1.24
'''
a=float(input())
print(f"a輸出到小數第二位是:{a:.2f}")
'''

#阿控制輸出就這樣
#再來講 if else
#就是判斷嘛 if ...: ... else : ...
'''
a=int(input())
if a>15:
    print(f"a={a} > 15")
else:
    print(f"a={a}<=15")
'''
# 喔但 其實if後面放的是一種變數型態 我沒講到
# 叫做 bool 布林 布林值只有兩種 True跟False
# if 裡面就是根據 True跟False決定要不要執行的
'''
a=int(input())
b=a>15
print(type(b))
print(b)
'''
# 如果有兩個條件要同時成立 可以用 and
# 如果有兩個條件符合一個就好 可以用 or
'''
a=int(input())
if a>15 and a<30:
    print(f"15<a={a}<30")
if a<=15 or a>=30:
    print(f"a={a}<=15 or a={a}>=30")
'''
# if之外還可以有 elif 跟 else
# elif 代表 如果if沒成立 那試試看elif的條件 成立就執行
# else 則是 所有條件都不符合 就執行
# 如果 上層的 if 或 elif 成立並執行了
# 下面的 elif 或 else 就不會再判斷或執行
'''
a=int(input())
if a>30:
    print(f"30<a={a}") 
elif a>15:
    print(f"15<a={a}<=30") #如果上面的if成立就不會執行這裡
else:
    print(f"a={a}<=15") #如果上面的 if或elif成立就不會執行這裡
'''
