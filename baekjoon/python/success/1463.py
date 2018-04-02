# https://www.acmicpc.net/problem/1463


def make_one(result_set, count=0):

    if 1 in result_set:
        return count

    tmp_set = set()

    for num in result_set:

        if num % 3 == 0:
            tmp_set.add(num / 3)

        if num % 2 == 0:
            tmp_set.add(num / 2)

        tmp_set.add(num - 1)

    count += 1

    return make_one(tmp_set - result_set, count)


if __name__ == "__main__":

    input_set = {int(input())}

    print(make_one(input_set))
