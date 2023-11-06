BITSTREAM = input("Enter the stream of bits: ")
count = 0
print("Before stuffing: ", BITSTREAM)
for i in range(len(BITSTREAM)):
  if BITSTREAM[i] == "1":
    count += 1
  elif BITSTREAM[i] == "0":
    count = 0
  if count == 5:
    BITSTREAM = BITSTREAM[:i+1] + '0' + BITSTREAM[i+1:]
print("After stuffing: ", BITSTREAM)
