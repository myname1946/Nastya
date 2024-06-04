class Array {
	public static void main(String args[]) {
		//Создание одномерного массива и вывод значения элементов на экран
		int nums[] = new int[10];
		int i;
		for(i = 0; i < 10; i++)
			nums[i] = i;
		for(i = 0; i < 10; i++)
			System.out.println("Элемент [" + i + "]: " + nums[i]);
		//Адьтернативнй способ инициализации массива
		int nums2[] = {99, 34, -7, 233, 76, -54, -76, 267, 987, 65};

		int min, max;
		//Поиск максимального и минимального значения
		min = max = nums2[0];
		for(i = 1; i < 10; i++) {
			if(nums2[i] < min) min = nums2[i];
			if(nums2[i] > max) max = nums2[i];
		}
		System.out.println("Минимальеное значение в массиве: " + min + "\nМаксимальное значение в массиве: " + max);
		//Пузырьковая сортировка массива nums2
		int a, b, t;
		int size = 10;
		System.out.println("Массив до сортировки:");
		for(i = 0; i < size; i++)
			System.out.println(" " + nums2[i]);
		System.out.println();

		for(a = 1; a < size; a++)
			for(b=size-1; b >= a; b--) {
				if(nums2[b-1] > nums2[b]) {
					t = nums2[b-1];
					nums2[b-1] = nums2[b];
					nums2[b] = t;
				}
			}
		System.out.println("Массив после сортировки:");
                for(i = 0; i < size; i++)
                        System.out.println(" " + nums2[i]);

	}
}
