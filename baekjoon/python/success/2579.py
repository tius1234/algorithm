# https://www.acmicpc.net/problem/2579


def climb_stairs(stair_list):

    if len(stair_list) < 1:
        return 0
    if len(stair_list) == 1:
        return stair_list[0]
    if len(stair_list) == 2:
        return stair_list[0] + stair_list[1]

    result_list = [
        stair_list[0],
        stair_list[0] + stair_list[1],
        max(stair_list[0], stair_list[1]) + stair_list[2]
    ]

    for ii in range(3, len(stair_list)):

        result_list.append(max(result_list[ii-3] + stair_list[ii-1], result_list[ii-2]) + stair_list[ii])

    return result_list[len(stair_list)-1]


if __name__ == "__main__":

    input_len = int(input())
    input_list = []

    for ii in range(input_len):
        input_list.append(int(input()))

    print(climb_stairs(input_list))
