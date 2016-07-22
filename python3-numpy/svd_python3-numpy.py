#!/usr/bin/env python3
import numpy as np
import numpy.linalg as la

np.set_printoptions(precision=18, linewidth=80, suppress=True)

m = [ \
    [1, -1, 2], \
    [1, 2, -3], \
    [1, 3, 1], \
]

s = sum(la.pinv(m)[0])

print(repr(np.float64(s-1)))
