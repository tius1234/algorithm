# https://www.acmicpc.net/problem/9095


def sum_one_two_three(num, result_dic={}):

    if num < 0:
        return 0
    elif num == 0:
        return 1

    if result_dic.get(num):
        return result_dic[num]

    if num >= 3:
        result_dic[num] = sum([
            sum_one_two_three(num-1),
            sum_one_two_three(num-2),
            sum_one_two_three(num-3)
        ])
    elif num == 2:
        result_dic[num] = sum([
            sum_one_two_three(num-1),
            sum_one_two_three(num-2)
        ])
    else:
        result_dic[num] = sum_one_two_three(num-1)

    return result_dic[num]


if __name__ == "__main__":

    input_len = int(input())
    input_list = []

    for ii in range(input_len):
        input_list.append(int(input()))

    for ii in input_list:
        print(sum_one_two_three(ii))
