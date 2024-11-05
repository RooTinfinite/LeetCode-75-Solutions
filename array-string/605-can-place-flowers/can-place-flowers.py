class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        f_length = len(flowerbed)
        if n == 0: return True
        if f_length == 1: return (not flowerbed[0])
        for i in range(f_length):
            if flowerbed[i] == 0:
                if i == 0:
                    if flowerbed[i] == 0 and flowerbed[i+1] == 0:
                        n -= 1
                        flowerbed[i] = 1
                        #print(f'{flowerbed} i:{i}')
                elif i == f_length - 1:
                    if flowerbed[f_length-2] == 0 and flowerbed[f_length-1] == 0:
                        n -= 1
                        flowerbed[i] = 1
                        #print(f'{flowerbed} i:{i}')
                else:
                    if flowerbed[i-1] == 0 and flowerbed[i+1] == 0:
                        n -= 1
                        flowerbed[i] = 1
                        #print(f'{flowerbed} i:{i}')

        #print(flowerbed)
        if n <= 0: return True
        else: return False

        