class Sorter:
    def sort(self, list, key=lambda x: x, cmp=None, reversed=False):
        if reversed:
            self._op = lambda x: not x
        else:
            self._op = lambda x: x

    def cmpNou(self, x, y):
        if x.get_descriere() < y.get_descriere():
            return True
        if x.get_descriere() == y.get_descriere() and x.get_data() < y.get_data():
            return True
        return False


class Comb_Sort(Sorter):
    def getNextGap(self, gap):
        gap = (gap * 10) // 13
        if gap < 1:
            return 1
        return gap

    def sort(self, list, key=lambda x: x, cmp=None, reversed=False):
        Sorter.sort(self, list, key, cmp, reversed)
        n = len(list)
        gap = n
        swapped = True
        while gap != 1 or swapped == True:
            gap = self.getNextGap(gap)

            swapped = False
            for i in range(0, n - gap):
                if self._op(cmp(key(list[i]), key(list[i + gap]))):
                    list[i], list[i + gap] = list[i + gap], list[i]
                    swapped = True
