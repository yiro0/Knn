# k-Nearest Neighbors (kNN) Algorithm Program

This program implements the **k-Nearest Neighbors (kNN)** algorithm. It was developed during the first semester of my studies for the *Computer Programming* subject.

The program processes data provided in `.txt` files and assigns labels to test data points based on how the kNN algorithm works.

---

## Input Data Format

### Training Dataset
Each point in the training dataset is described with:
- A **label** (text string)
- A sequence of **`D` numbers** (attributes)

**Example:**  
label_B 90.07 -50.69 -36.57 84.24 -40.52 -52.38 -94.11  
label_C -93.47 12.67 -53.09 -57.06 -45.26 13.28 38.76  
label_D -25.01 -43.38 15.18 -79.20 -93.45 -37.42 -40.66  
...

- Any number of points in a file is valid.
- All points must have the same number of attributes.

### Test Dataset
Each point in the test dataset is described with:
- A sequence of `D` attributes (no labels)

**Example:**  
1.5 12.3  
4 7.6  
0.2 -0.9  
-6 3.15  
...

---

## Preparing Input Data

The program does not create the `.txt` files for the training or test datasets. You must manually create these files in the required format (as described in the "Input Data Format" section) and place them in the **build directory** where the program is executed.

### Example File Creation
You can create the `.txt` files using any text editor. For example:

- `train_dataset.txt`:  
  label_B 7.6 5.3  
  label_C 45.3 4.6  
  label_A -3.7 22.9  
  ...

- `test_dataset.txt`:  
  1.5 12.3  
  4 7.6  
  0.2 -0.9  
  ...

**Ensure that the files are saved in the build directory before running the program.**

---

## Output Data Format

The program uses the training dataset to assign labels to points in the test dataset.

The output file has the same format as the training dataset, with **labels added** to the test points.

**Example:**  
label_C 1.5 12.3  
label_A 4 7.6  
label_A 0.2 -0.9  
label_C -6 3.15  
...

---

## How to Run the Program

The program is executed from the command line with the following switches:

| Switch   | Description                   |
|----------|-------------------------------|
| `-train` | Input training dataset file   |
| `-test`  | Input test dataset file       |
| `-out`   | Output file                   |
| `-k`     | Number of k nearest neighbors |

### Example Command
```bash
./knn_program -train train_dataset.txt -test test_dataset.txt -out output.txt -k 3
```

### Help
Running the program with no parameters will display a short help message explaining how to use the program.
