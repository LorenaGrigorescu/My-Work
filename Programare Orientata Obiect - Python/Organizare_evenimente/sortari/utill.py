class Sortare:
    def __negation(self, x):
        return not x

    def __identity(self, x):
        return x

    def QuickSort(self, lista, key=lambda x:x, cmp=lambda x, y:x<y, reversed=False):
        if reversed == True:
            operation = self.__negation
        else:
            operation = self.__identity
        self.__quick_sort_r(lista, key, cmp, operation, 0, len(lista) - 1)

    def __quick_sort_r(self, lista, key, cmp, operation, st, dr):
        if st < dr:
            p = self.__partitie(lista, key, cmp, operation, st, dr)
            self.__quick_sort_r(lista, key, cmp, operation, st, p - 1)
            self.__quick_sort_r(lista, key, cmp, operation, p + 1, dr)

    def __partitie(self, lista, key, cmp, operation, st, dr):
        p = st
        i = st + 1
        j = dr
        while i <= j:
            if operation(cmp(key(lista[p]), key(lista[i]))):
                lista[i], lista[j] = lista[j], lista[i]
                j -= 1
            else:
                lista[i], lista[p] = lista[p], lista[i]
                p += 1
                i += 1
        return p


