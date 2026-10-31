# Von Neumann architecture

From [The emergence of the Cognitive-Compiler and the evolution of the AI stack](https://medium.com/@jmhuertany/the-emergence-of-the-cognitive-compiler-and-the-evolution-of-the-ai-stack-2ce04930318a)

1. 1936 : Turing machine — theoretical bound. Defines what is computable. Nothing above this layer can escape it. |
2. 1945 : Von Neumann architecture. Physical instantiation. Stored program. Fetch-decode-execute.
3. 1950s–70s: Assembler → compiler (FORTRAN, C). Human syntax → machine code. Deterministic. No emergent behavior.
4. 1980s–2000s: OOP, frameworks, runtimes. Higher abstraction. Mostly deterministic (some compiler-based optimization for specific instruction (e.g., branching)). Human writes every instruction.
5. 2010s: Cloud platforms, APIs, SDKs. Composition over construction. Distributed/Remote Computation. Significant horizontal scalability. Human orchestrates at API abstraction level; machine executes.
6. 2022+ Frontier LLMs and AI Agents — as emergent compiler. Human intent → generated code. Non-deterministic. Emergent capabilities.

[CPU, GPU & TPU image](./files/clase01/CPU-GPU-TPU.jpg) -- Nice image from article

[Single instruction, multiple data @ Wikipedia](https://en.wikipedia.org/wiki/Single_instruction,_multiple_data#Lanes) (SIMD) vs [Single instruction, multiple threads @ Wikipedia](https://en.wikipedia.org/wiki/Single_instruction,_multiple_threads) (SIMT)

Also [Digital signal processor @ Wikipedia](https://en.wikipedia.org/wiki/Digital_signal_processor)

## Does DSP architecture still exist?

Dedicated DSP architectures still exist and are widely used, especially in real‑time, low‑power, and embedded signal‑processing applications.

## Why DSP architectures persist

DSPs are specialized microprocessors optimized for digital signal processing tasks such as filtering, FFTs, convolution, and matrix operations

Their architecture includes features that general-purpose CPUs typically lack:
- Multiply–accumulate (MAC) units for fast arithmetic
- Specialized addressing modes like circular buffers and bit‑reversed addressing for FFTs
- Modified Harvard architecture with multiple data buses for parallel access
- Zero‑overhead looping and pipelined execution for deterministic real‑time performance
- Fixed‑point and floating‑point variants tailored to different workloads

These architectural traits make DSPs ideal for systems where latency, determinism, and power efficiency matter.

## Evidence from modern DSP products

The supplied results show that major vendors still produce advanced DSP families, confirming that DSP architecture is alive and evolving:

- Texas Instruments C6000 series: up to 8000 MIPS, VLIW architecture, floating‑point support
- Freescale MSC81xx: multi‑core StarCore DSPs at 1 GHz per core
- XMOS processors: multi‑core, multi‑threaded devices supporting up to 32 real‑time threads
- CEVA DSP families: VLIW + SIMD designs with up to 32 MAC units for SDR and communications
- Analog Devices SHARC and Blackfin: high‑performance floating‑point DSPs used in audio, industrial control, and more...
- NXP TriMedia: VLIW DSPs optimized for audio/video processing

These are all current-generation DSP architectures, not legacy designs.

## Where DSPs are used today

DSPs remain essential in domains where real-time processing and efficiency are critical:
- Telecommunications and wireless (modulation, demodulation, channel estimation)
- Audio processing (filters, equalization, noise reduction)
- Image and video processing (compression, filtering)
- Radar, sonar, and sensor arrays
- Embedded control systems (motor control, robotics)
- Consumer electronics (mobile phones, HDTV, disk drives)

DSPs are also used in satellites, where replacing analog filters with DSPs reduces weight and power consumption

## How DSPs coexist with CPUs, GPUs, and FPGAs

While DSP algorithms increasingly run on multi-core CPUs and many-core GPUs for high-throughput workloads, dedicated DSPs remain superior when:
- Power consumption must be minimal (mobile, IoT, battery-powered devices).
- Latency must be deterministic (communications, control loops).
- Hardware-level DSP instructions provide major speedups (MAC, circular buffers, FFT modes).

Thus, DSP architecture has not disappeared — it has diversified.

## Bottom line

DSP architecture absolutely still exists. It remains a core technology in modern embedded systems, communications, audio/video processing, and real-time applications, even as general-purpose processors and GPUs take on more DSP workloads.
