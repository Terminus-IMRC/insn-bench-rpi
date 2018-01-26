# insn-bench-rpi

Yet another instruction benchmark program mainly for Raspberry Pi 2 and 3.


## Building

```
$ make
```


## Running

* Raspberry Pi 2

```
vadd.f32 s:  4.00  1.06  1.10
vadd.f32 d:  4.00  2.13  2.20
vadd.f32 q:  4.13  4.25  4.40
vmul.f32 s:  4.00  1.06  1.10
vmul.f32 d:  4.00  2.13  2.20
vmul.f32 q:  4.13  4.25  4.40
vmla.f32 s:  8.00  1.06  1.10
vmla.f32 d:  8.00  2.13  2.20
vmla.f32 q:  8.00  4.25  4.40
vdiv.f32 s: 18.00 15.00 15.00
```

* Raspberry Pi 3

```
vadd.f32 s:  4.00  0.56  0.60
vadd.f32 d:  4.00  0.56  0.60
vadd.f32 q:  4.00  1.13  1.20
vmul.f32 s:  4.00  0.56  0.60
vmul.f32 d:  4.00  0.56  0.60
vmul.f32 q:  4.00  1.13  1.20
vmla.f32 s:  8.00  0.56  0.70
vmla.f32 d:  8.00  0.56  0.70
vmla.f32 q:  8.00  1.13  1.20
vdiv.f32 s: 13.00 10.00 10.00
```
