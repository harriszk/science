import numpy as np

def rref(A):
    """Compute the reduced row echelon form of A using Gaussian elimination"""
    n, m = A.shape
    i, j = 0, 0
    while i < n and j < m:
        # Find pivot in column j, starting in row i:
        pivot_index = np.argmax(np.abs(A[i:, j])) + i
        if A[pivot_index, j] != 0:
            # Swap rows i and pivot_index
            A[[i, pivot_index]] = A[[pivot_index, i]]
            # Normalize pivot row
            pivot = A[i, j]
            A[i] = A[i] / pivot
            # Eliminate all other non-zero entries in column j
            for k in range(n):
                if k != i:
                    A[k] = A[k] - A[k, j] * A[i]
            i += 1
        j += 1
    return A

def linear_solver(A, b):
    """Solves a system of linear equations represented by the matrix A and the vector b"""
    # Append b to A
    Ab = np.column_stack((A, b))
    # Compute the reduced row echelon form of Ab
    rref_Ab = rref(Ab)
    n, m = A.shape
    x = np.zeros(n)
    for i in range(n):
        if rref_Ab[i, m] != 0 and np.all(rref_Ab[i, :m] == 0):
            # This row represents an equation of the form x_i = b_i,
            # so x_i is a free variable and can be set to any value
            return None
        elif rref_Ab[i, m] != 0:
            # This row represents an equation of the form x_i = b_i,
            # so x_i can be solved for
            x[i] = rref_Ab[i, m]
    return x

A = np.array([[35.453, 79.904], [22.99, 22.99]])
b = np.array([1.25, 0.75])
x = linear_solver(A, b)
print(x)