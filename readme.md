*This project has been created as part of the 42 curriculum by mucelep, ckurtul.*

---

# push_swap

> Because Swap_push doesn't feel as natural.

## Description

**push_swap** is a sorting algorithm project where the goal is to sort a stack of integers using two stacks (`a` and `b`) and a limited set of operations, while minimizing the total number of operations used.

The project enforces a rigorous understanding of algorithmic complexity. Four distinct sorting strategies must be implemented, and the program selects the appropriate one either automatically (based on disorder level) or via a command-line flag.

**Available operations:**

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the top 2 elements of stack a |
| `sb` | Swap the top 2 elements of stack b |
| `ss` | `sa` and `sb` simultaneously |
| `pa` | Push top of stack b onto stack a |
| `pb` | Push top of stack a onto stack b |
| `ra` | Rotate stack a upward (first becomes last) |
| `rb` | Rotate stack b upward |
| `rr` | `ra` and `rb` simultaneously |
| `rra` | Reverse rotate stack a (last becomes first) |
| `rrb` | Reverse rotate stack b |
| `rrr` | `rra` and `rrb` simultaneously |

---

## Instructions

### Compilation

```bash
make        # Compiles push_swap
make bonus  # Compiles checker (bonus)
make clean  # Removes object files
make fclean # Removes object files and binaries
make re     # Full recompile
```

### Usage

```bash
./push_swap [--simple | --medium | --complex | --adaptive] <integers...>
```

**Strategy flags:**

| Flag | Description |
|------|-------------|
| `--simple` | Forces O(n²) algorithm |
| `--medium` | Forces O(n√n) algorithm |
| `--complex` | Forces O(n log n) algorithm |
| `--adaptive` | Selects strategy based on disorder (default) |

**Optional benchmark flag:**

```bash
./push_swap --bench --adaptive 4 67 3 87 23
```

Outputs to `stderr`: disorder percentage, strategy used, total operations, and per-operation counts.

### Examples

```bash
# Sort a small list
./push_swap 2 1 3 6 5 8

# Count operations for 5 numbers
ARG="4 67 3 87 23"; ./push_swap --adaptive $ARG | wc -l

# Force complex strategy and verify with checker
ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./checker $ARG

# Sort 500 random numbers
shuf -i 0-9999 -n 500 > args.txt; ./push_swap $(cat args.txt) | wc -l
```

### Error Handling

```bash
./push_swap 0 one 2 3   # Error: non-integer argument
./push_swap 3 2 3       # Error: duplicate value
```

---

## Algorithms

### Disorder Metric

Before selecting a strategy, the program computes a **disorder score** between `0.0` (fully sorted) and `1.0` (fully reversed), defined as the ratio of inverted pairs to total pairs:
disorder = mistakes / total_pairs
where a "mistake" is any pair `(i, j)` where `i < j` but `a[i] > a[j]`.

---

### Strategy 1 — Simple: O(n²)

**Algorithm:** Insertion sort adaptation.

Each element from stack `a` is moved to stack `b` in sorted order by rotating `b` to find the correct insertion position. Once all elements are in `b`, they are pushed back to `a`.

**Complexity argument:**
For each of the `n` elements, finding the insertion position in `b` costs at most `n` rotations → **O(n²)** operations total.

**When used:** `--simple` flag, or adaptive regime with `disorder < 0.2`.

---

### Strategy 2 — Medium: O(n√n)

**Algorithm:** Chunk-based sorting with √n chunks.

The input is divided into ~√n value ranges (chunks). Elements are pushed to `b` chunk by chunk, largest chunk first. Stack `b` is then rebuilt back into `a` in sorted order by always finding the cheapest push.

**Complexity argument:**
There are √n chunks of size √n. For each chunk, locating and rotating each element costs O(√n) on average → **O(n√n)** operations total.

**When used:** `--medium` flag, or adaptive regime with `0.2 ≤ disorder < 0.5`.

---

### Strategy 3 — Complex: O(n log n)

**Algorithm:** Radix sort adaptation (LSD — Least Significant Digit).

Elements are assigned normalized integer ranks (0 to n−1). Bits are processed from least to most significant. On each bit pass, elements with bit=0 stay in `a` and elements with bit=1 are pushed to `b`, then all are merged back. After `log₂(n)` passes, the stack is sorted.

**Complexity argument:**
Each pass touches all `n` elements. There are `log₂(n)` passes → **O(n log n)** operations total. No comparisons between elements are needed.

**When used:** `--complex` flag, or adaptive regime with `disorder ≥ 0.5`.

---

### Strategy 4 — Adaptive

The adaptive strategy automatically selects one of the above based on measured disorder:

| Disorder range | Selected strategy | Complexity |
|----------------|-------------------|------------|
| `disorder < 0.2` | Simple (insertion sort) | O(n²) |
| `0.2 ≤ disorder < 0.5` | Medium (chunk sort) | O(n√n) |
| `disorder ≥ 0.5` | Complex (radix sort) | O(n log n) |

**Threshold rationale:**
- When disorder is very low, the stack is nearly sorted. Insertion sort excels here as it can detect and exploit existing order with very few operations.
- Medium disorder benefits from chunking: enough structure is missing that a pure O(n²) approach gets expensive, but full bit-level sorting is overkill.
- High disorder means the data is essentially random. Radix sort's consistent O(n log n) behavior makes it the clear winner.

**Space complexity (Push_swap model):**
All strategies use only the two stacks (`a` and `b`) and a constant amount of auxiliary memory for index tracking → **O(n)** space in all regimes.

This is the **default behavior** when no strategy flag is given.

---

## Performance Targets

| Input size | Minimum (pass) | Good | Excellent |
|------------|----------------|------|-----------|
| 100 numbers | < 2000 ops | < 1500 ops | < 700 ops |
| 500 numbers | < 12000 ops | < 8000 ops | < 5500 ops |

---

## Bonus — Checker

The `checker` program reads a list of push_swap operations from `stdin` and verifies whether they correctly sort the given stack.

```bash
./checker 3 2 1 0
rra
pb
sa
rra
pa
OK
```

Displays `OK` if stack `a` is sorted and stack `b` is empty after all operations; `KO` otherwise.

---

## Resources

### Algorithm References

- [Wikipedia — Sorting algorithm](https://en.wikipedia.org/wiki/Sorting_algorithm)
- [Visualgo — Sorting visualizer](https://visualgo.net/en/sorting)
- [Big-O Cheat Sheet](https://www.bigocheatsheet.com/)
- [Radix Sort — GeeksForGeeks](https://www.geeksforgeeks.org/radix-sort/)
- [Introduction to Algorithms (CLRS)](https://mitpress.mit.edu/9780262046305/introduction-to-algorithms/) — Chapters on sorting and complexity

### push_swap Specific

- [Medium — push_swap: a journey through sorting algorithms](https://medium.com/@jamierobertdawson/push-swap-the-least-number-of-moves-with-two-stacks-d1e76a71789a)
- [42 Docs push_swap resources](https://harm-smits.github.io/42docs/projects/push_swap)

### AI Usage

AI tools (Claude) were used in this project for the following tasks:

- **Complexity analysis:** Verifying the operation-count upper bounds for each strategy within the Push_swap model.
- **Debugging assistance:** Identifying off-by-one errors in rotation logic during development.
- **README drafting:** Initial structure and wording of this document, reviewed and edited by both learners.
- **Test case generation:** Generating edge-case input lists (already-sorted, reverse-sorted, duplicates) for manual testing.

All AI-generated content was reviewed, understood, and validated by both project members before inclusion.

---

## Contributors

| Login | Contributions |
|-------|--------------|
| mucelep | *(describe your contributions here)* |
| ckurtul | *(describe your contributions here)* |

---
---

# push_swap (Türkçe)

> Çünkü Swap_push o kadar doğal hissettirmiyor.

## Açıklama

**push_swap**, iki yığın (`a` ve `b`) ile sınırlı bir operasyon seti kullanarak tam sayıları sıralayan ve toplam operasyon sayısını minimize etmeyi hedefleyen bir sıralama algoritması projesidir.

Proje, algoritmik karmaşıklığın somut şekilde kavranmasını zorunlu kılar. Dört farklı sıralama stratejisi uygulanmalı; program, uygun stratejiyi otomatik olarak (düzensizlik düzeyine göre) ya da komut satırı bayrağıyla seçmelidir.

**Kullanılabilir operasyonlar:**

| Operasyon | Açıklama |
|-----------|----------|
| `sa` | Yığın a'nın üstteki 2 elemanını yer değiştirir |
| `sb` | Yığın b'nin üstteki 2 elemanını yer değiştirir |
| `ss` | `sa` ve `sb`'yi aynı anda uygular |
| `pa` | Yığın b'nin tepesini yığın a'ya iter |
| `pb` | Yığın a'nın tepesini yığın b'ye iter |
| `ra` | Yığın a'yı yukarı döndürür (ilk eleman son olur) |
| `rb` | Yığın b'yi yukarı döndürür |
| `rr` | `ra` ve `rb`'yi aynı anda uygular |
| `rra` | Yığın a'yı aşağı döndürür (son eleman ilk olur) |
| `rrb` | Yığın b'yi aşağı döndürür |
| `rrr` | `rra` ve `rrb`'yi aynı anda uygular |

---

## Kurulum ve Kullanım

### Derleme

```bash
make        # push_swap'ı derler
make bonus  # checker'ı derler (bonus)
make clean  # nesne dosyalarını siler
make fclean # nesne dosyalarını ve ikili dosyaları siler
make re     # tamamen yeniden derler
```

### Kullanım

```bash
./push_swap [--simple | --medium | --complex | --adaptive] <tam sayılar...>
```

**Strateji bayrakları:**

| Bayrak | Açıklama |
|--------|----------|
| `--simple` | O(n²) algoritmasını zorlar |
| `--medium` | O(n√n) algoritmasını zorlar |
| `--complex` | O(n log n) algoritmasını zorlar |
| `--adaptive` | Düzensizliğe göre strateji seçer (varsayılan) |

**İsteğe bağlı kıyaslama bayrağı:**

```bash
./push_swap --bench --adaptive 4 67 3 87 23
```

`stderr`'e çıktı verir: düzensizlik yüzdesi, kullanılan strateji, toplam operasyon sayısı ve her operasyon türünün sayısı.

### Örnekler

```bash
# Küçük bir listeyi sırala
./push_swap 2 1 3 6 5 8

# 5 sayı için operasyon sayısını say
ARG="4 67 3 87 23"; ./push_swap --adaptive $ARG | wc -l

# Complex stratejiyi zorla ve checker ile doğrula
ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./checker $ARG

# 500 rastgele sayıyı sırala
shuf -i 0-9999 -n 500 > args.txt; ./push_swap $(cat args.txt) | wc -l
```

### Hata Yönetimi

```bash
./push_swap 0 one 2 3   # Hata: tam sayı olmayan argüman
./push_swap 3 2 3       # Hata: yinelenen değer
```

---

## Algoritmalar

### Düzensizlik Metriği

Strateji seçilmeden önce program, `0.0` (tamamen sıralı) ile `1.0` (tamamen tersine çevrilmiş) arasında bir **düzensizlik skoru** hesaplar:
düzensizlik = hatalar / toplam_çift
"Hata", `i < j` olmasına rağmen `a[i] > a[j]` olan her `(i, j)` çiftidir.

---

### Strateji 1 — Basit: O(n²)

**Algoritma:** Ekleme sıralaması uyarlaması.

Yığın `a`'daki her eleman, doğru ekleme konumunu bulmak için `b`'yi döndürerek sıralı biçimde yığın `b`'ye taşınır. Tüm elemanlar `b`'ye geçince geri `a`'ya itilir.

**Karmaşıklık argümanı:**
Her `n` eleman için `b`'de doğru konum bulmak en fazla `n` döndürme gerektirir → toplamda **O(n²)** operasyon.

**Ne zaman kullanılır:** `--simple` bayrağı veya `disorder < 0.2` olan uyarlanabilir rejim.

---

### Strateji 2 — Orta: O(n√n)

**Algoritma:** √n parçalı (chunk) sıralama.

Girdi yaklaşık √n değer aralığına bölünür. Elemanlar parça parça, en büyük parçadan başlayarak `b`'ye itilir. Ardından `b` yığını, her seferinde en ucuz itmeyi bularak `a`'ya geri aktarılır.

**Karmaşıklık argümanı:**
√n boyutunda √n parça vardır. Her parça için eleman bulmak ve döndürmek ortalama O(√n) maliyetlidir → toplamda **O(n√n)** operasyon.

**Ne zaman kullanılır:** `--medium` bayrağı veya `0.2 ≤ disorder < 0.5` olan uyarlanabilir rejim.

---

### Strateji 3 — Karmaşık: O(n log n)

**Algoritma:** Radix sort uyarlaması (LSD — En Az Anlamlı Basamak).

Elemanlara 0'dan n−1'e normalize edilmiş tamsayı sıraları atanır. Bitler en az anlamlıdan en çok anlamlıya doğru işlenir. Her bit geçişinde bit=0 olanlar `a`'da kalır, bit=1 olanlar `b`'ye itilir; ardından tümü geri birleştirilir. `log₂(n)` geçişin ardından yığın sıralanmış olur.

**Karmaşıklık argümanı:**
Her geçiş tüm `n` elemana dokunur. `log₂(n)` geçiş vardır → toplamda **O(n log n)** operasyon.

**Ne zaman kullanılır:** `--complex` bayrağı veya `disorder ≥ 0.5` olan uyarlanabilir rejim.

---

### Strateji 4 — Uyarlanabilir

| Düzensizlik aralığı | Seçilen strateji | Karmaşıklık |
|---------------------|------------------|-------------|
| `disorder < 0.2` | Basit (ekleme sıralaması) | O(n²) |
| `0.2 ≤ disorder < 0.5` | Orta (parça sıralama) | O(n√n) |
| `disorder ≥ 0.5` | Karmaşık (radix sort) | O(n log n) |

**Eşik değeri gerekçesi:**
- Düzensizlik çok düşük olduğunda yığın neredeyse sıralıdır. Ekleme sıralaması mevcut düzeni az operasyonla kullanır.
- Orta düzeyde düzensizlikte saf O(n²) pahalı olmaya başlar, tam bit düzeyli sıralama ise gereğinden fazladır.
- Yüksek düzensizlikte veri temelde rastgeledir. Radix sort'un tutarlı O(n log n) davranışı açık kazanandır.

**Alan karmaşıklığı:** Tüm stratejiler yalnızca iki yığını kullanır → tüm rejimlerde **O(n)** alan.

Bu, hiçbir strateji bayrağı verilmediğinde **varsayılan davranıştır**.

---

## Performans Hedefleri

| Girdi boyutu | Minimum (geçer) | İyi | Mükemmel |
|--------------|----------------|-----|----------|
| 100 sayı | < 2000 ops | < 1500 ops | < 700 ops |
| 500 sayı | < 12000 ops | < 8000 ops | < 5500 ops |

---

## Bonus — Checker

`checker` programı, `stdin`'den push_swap operasyonlarının listesini okur ve bunların verilen yığını doğru şekilde sıralayıp sıralamadığını doğrular.

```bash
./checker 3 2 1 0
rra
pb
sa
rra
pa
OK
```

Yığın `a` sıralı ve yığın `b` boşsa `OK`, aksi takdirde `KO` gösterir.

---

## Kaynaklar

### Algoritma Referansları

- [Wikipedia — Sıralama algoritması](https://en.wikipedia.org/wiki/Sorting_algorithm)
- [Visualgo — Sıralama görselleştirici](https://visualgo.net/en/sorting)
- [Big-O Kopya Kağıdı](https://www.bigocheatsheet.com/)
- [Radix Sort — GeeksForGeeks](https://www.geeksforgeeks.org/radix-sort/)
- [Algoritmalara Giriş (CLRS)](https://mitpress.mit.edu/9780262046305/introduction-to-algorithms/)

### push_swap'a Özel

- [Medium — push_swap: sıralama algoritmaları yolculuğu](https://medium.com/@jamierobertdawson/push-swap-the-least-number-of-moves-with-two-stacks-d1e76a71789a)
- [42 Docs push_swap kaynakları](https://harm-smits.github.io/42docs/projects/push_swap)

### Yapay Zeka Kullanımı

Bu projede yapay zeka araçları (Claude) aşağıdaki görevler için kullanılmıştır:

- **Karmaşıklık analizi:** Push_swap modelinde her strateji için operasyon sayısı üst sınırlarının doğrulanması.
- **Hata ayıklama desteği:** Döndürme mantığındaki hataların tespit edilmesi.
- **README taslağı:** Bu belgenin ilk yapısı ve ifadeleri, her iki öğrenci tarafından incelenerek düzenlenmiştir.
- **Test senaryosu üretimi:** Sınır durumu girdi listelerinin oluşturulması.

Tüm yapay zeka içerikleri her iki proje üyesi tarafından incelenerek doğrulanmıştır.

---

## Katkıda Bulunanlar

| Login   | Katkılar |
|---------|----------|
| mucelep | *(katkılarını buraya yaz)* |
| ckurtul | *(katkılarını buraya yaz)* |