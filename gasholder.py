class GasHolder:
    def __init__(self, V):
        try:
            self.V = V
            if self.V < 0:
                raise ValueError("V must be greater than 0")
        except ValueError as err:
            print(err)

    N = 0
    T = 273

    def inject(self, m, M):
        try:
            if m < 0 or M < 0:
                raise ValueError("m and M must be greater then 0")
            self.N += m/M
        except ValueError as err:
            print(err)

    def cool (self, dT):
        self.T -= dT
        if self.T < 0: self.T = 0

    def get_preasure(self):
        return self.N/self.N * 8.31 * self.T
