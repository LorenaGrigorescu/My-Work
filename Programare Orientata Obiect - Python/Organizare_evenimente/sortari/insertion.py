class Sorter:
    def sort(self, list, key=lambda x: x, cmp=lambda x, y: x < y, reversed=False):
        if reversed:
            self._op = lambda x: not x
        else:
            self._op = lambda x: x


class Insertion_Sorter(Sorter):
    def sort(self, list, key=lambda x: x, cmp=lambda x, y: x < y, reversed=False):
        Sorter.sort(self, list, key, cmp, reversed)
        for i in range(1, len(list)):
            j = i
            while j > 0 and self._op(cmp(key(list[j]), key(list[j - 1]))):
                list[j - 1], list[j] = list[j], list[j - 1]
                j -= 1

