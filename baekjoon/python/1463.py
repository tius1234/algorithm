# https://www.acmicpc.net/problem/1463

def make_one(num, cnt=0, num_dic={}):
    
    if num == 1:
        return cnt

    if num_dic.get(num):
        return num_dic.get(num)

    cnt += 1

    if num % 3 == 0 and num % 2 == 0:

        num_dic[num / 2] = make_one(num / 2, cnt, num_dic)
        num_dic[num / 3] = make_one(num / 3, cnt, num_dic)
        num_dic[num - 1] = make_one(num - 1, cnt, num_dic)
        
        return min(
            num_dic[num / 2],
            num_dic[num / 3],
            num_dic[num - 1]
        )

    elif num % 3 == 0:

        num_dic[num / 3] = make_one(num / 3, cnt, num_dic)
        num_dic[num - 1] = make_one(num - 1, cnt, num_dic)
        
        return min(
            num_dic[num / 3],
            num_dic[num - 1]
        )

    elif num % 2 == 0:

        num_dic[num / 2] = make_one(num / 2, cnt, num_dic)
        num_dic[num - 1] = make_one(num - 1, cnt, num_dic)
        
        return min(
            num_dic[num / 2],
            num_dic[num - 1]
        )

    else:

        num_dic[num - 1] = make_one(num - 1, cnt, num_dic)        
        return num_dic[num - 1]

if __name__ == "__main__":

    print(make_one(10))
