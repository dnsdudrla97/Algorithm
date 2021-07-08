




doc = ''' 
Quick -> 분할 정복 알고리즘 -> 완전히 정렬될 때 까지 두 목록을 재귀적으로 정렬
python : list.sort() function
    -> 프로그래밍 언어 차원에서 기본적으로 지원되는 내장 정렬 함수는 대부분은 퀵정렬을 기본으로 한다.
    (성능)-> 일반적으로 원소의 개수가 적어질 수 록 나쁜 중간값이 선택될 확률이 높아지기 때문에 
        원소의 개수에 따라 퀵 정렬에 다른 정렬을 혼합해서 사용 하는 경우가 많다.
    -> 병합 정렬과 퀵 정렬은 분할 정복과 재귀 알고리즘을 사용한다는 측면에서는 유사하지만
        내부적으로 정렬을 하는 방식에서는 큰 차이가 있다.
    -> 병합 정렬은 항상 정 중앙을 기준으로 단순 분할 후 병합 시점에서 값의 비교 연산이 발생한다.
    -> 퀵 정렬은 분할 시점부터 비교 연산이 일어나기 때문에 그 이후 병합에 들어가는 비용이 매우적거나
        구현 방법에 따라서 아예 병합을 하지 않을 수 있다.

    복잡도
    -> 퀵 정렬의 성능은 어떻게 Pivot 값을 선택하느냐에 크게 달라질 수 있다.!
        -> pivot 값을 기준으로 동일한 개수의 작은 값, 큰 값들이 분할되어 O(NlogN)의 시간 복잡도를 갖는다.
        -> pivot 값을 기준으로 분할 했을 때 값들이 한 편으로 크게 치우치게 되면
            퀵 정렬은 성능은 저하되게 되며, 최악의 경우 한편으로만 모든 값이 몰리게 되어 O(N^2)의 시간복잡도를 갖는다.
    -> 상용 코드 
        -> 중앙값 (median)에 가까운 pivot 값을 선택할 수 있는 섬세한 전략이 요구된다.
        -> 배열의 첫 값과 중앙 값 그리고 마지막 값 중에 크기가 중간이 값을 사용하는 방법이 많이 사용된다.
        -> 퀵 정렬은 공간 복잡도는 구현 방법에 따라 달라질 수 있는데, 입력 배열이 차지하는
        메모리만을 사용하는 in-place sorting 방식으로 구현을 사용할 경우 O(1)의 공간 복잡도를 가진
        코드의 구현이 가능

    구현
        -> 리스트의 정 가운데 있는 값 pivot값으로 선택
        -> pivot 값 보다 작은 값
        -> 동일한 값
        -> 큰 값 을 담을 3개의 리스트를 생성한다.
        -> 반복문을 통해 각 값을 pivot 과 비교 후에 해당 하는 리스트에 추가시킨다.
        -> 다음 작은 값과 큰 값을 담고 있는 배열을 대상으로 퀵 정렬 함수를 재귀적으로 호출한다.
        -> 마지막으로 재귀 호출의 결과를 다시 크기 순을 합치면 정렬된 리스트를 얻을 수 있다.
    -> 입력 목록을 분할 하는 목록을 분할하는 것을 목록 분활이라고 함
'''
from random import randint
from timeit import repeat

def gen_random_lsit(num):
    randomList = []
    for i in range(0, num):
        randomList.append(randint(0, 9999999))

    return randomList

def run_sorting_algorithm(algorithm, array):
    
    
    
    setup_code = f"from __main__ import {algorithm}" \
        if algorithm != "sorted" else ""

    stmt = f"{algorithm}({array})"

    
    
    times = repeat(setup=setup_code, stmt=stmt, repeat=3, number=10)

    
    
    print(f"Algorithm: {algorithm}. Minimum execution time: {min(times)}")

def quicksort(array):
    
    
    if len(array) < 2:
        return array

    low, same, high = [], [], []

    
    pivot = array[randint(0, len(array) - 1)]

    for item in array:
        
        
        
        
        if item < pivot:
            low.append(item)
        elif item == pivot:
            same.append(item)
        elif item > pivot:
            high.append(item)

    
    
    
    return quicksort(low) + same + quicksort(high)

if __name__ == "__main__":
    dataset = gen_random_lsit(10000)
    print(dataset)

    run_sorting_algorithm("quicksort", array=dataset)
    