# Repository Structure Proposal (Minimal Intrusion Version)

## Objective

Keep the original sample folder/file names **as intact as possible**, while still enabling:
- Visual Studio 2022 project integration
- Clean multi-project solution structure
- Portfolio-level organization

---

## Key Principle

> Do NOT rename or heavily restructure original sample folders.
> Wrap them instead.

---

## Recommended Folder Structure

```
frank-luna-dx9/
├── build/
├── external/
│
├── engine/                        # New (shared code extraction target)
│   ├── include/
│   └── src/
│
├── samples/                       # Wrapper layer (NEW)
│   ├── ch01_d3d_init/
│   │   ├── project/               # VS project lives here
│   │   └── source/                # original code (copied or referenced)
│   │
│   ├── ch03_shapes/
│   └── ...
│
├── legacy/                        # ORIGINAL STRUCTURE (UNCHANGED)
│   ├── Book Part II Code/
│   │   ├── Chapter 1/D3D9 Init/
│   │   ├── Chapter 3/
│   │   ├── Chapter 4/Colore Triangle/
│   │   ├── Chapter 5/
│   │   ├── Chapter 6/
│   │   ├── Chapter 7/
│   │   └── Chapter 8/
│   │
│   └── Book Part III Code/
│       ├── Chapter 9/
│       ├── Chapter 10/
│       ├── Chapter 11/
│       ├── Chapter 12/Camera/
│       ├── Chapter 13/
│       ├── Chapter 14/
│       └── Chapter 15/Pick/
│
├── assets/
│   ├── textures/
│   └── meshes/
│
├── frank-luna-dx9.sln
└── README.md
```

---

## Two Viable Integration Strategies

### Strategy A (Recommended): Reference Existing Files

Each sample project:
- Keeps original files in `legacy/`
- Visual Studio project references them via relative paths

Example:
```
samples/ch01_d3d_init/project/
    → references ../../../legacy/Book Part II Code/Chapter 1/D3D9 Init/*.cpp
```

Pros:
- No duplication
- Preserves original structure completely
- Cleaner diff vs original book code

Cons:
- Slightly more complex VS configuration

---

### Strategy B: Copy Per Sample (Simpler)

```
samples/ch01_d3d_init/source/
```

- Copy only the required files from legacy
- Keep filenames identical

Pros:
- Simple setup
- Independent projects

Cons:
- Duplication

---

## Naming Policy

- DO NOT rename:
  - `.cpp`, `.h`
  - internal file structure
- Only normalize:
  - top-level sample folder names (for clarity)

Example mapping:

| Original | Wrapper |
|--------|--------|
| Chapter 1/D3D9 Init | ch01_d3d_init |
| Chapter 4/Colore Triangle | ch04_colored_triangle |

---

## Engine Extraction (Optional but Recommended)

Gradually move duplicated code into:

```
engine/
```

Typical candidates:
- d3dUtility
- initialization code
- camera (later chapters)

Important:
- Do this incrementally
- Do NOT break original samples immediately

---

## Visual Studio Setup (Concept)

- One Solution:
  - frank-luna-dx9.sln

- Projects:
  - engine (optional at first)
  - one project per sample

Each sample project:
- Output: executable
- Includes either:
  - referenced legacy files OR copied source

---

## What This Achieves

- Preserves original book integrity
- Enables modern development workflow
- Adds strong portfolio signal:
  > "Can integrate legacy code into structured system"

---

## Final Recommendation

Start with:

1. Strategy A (reference original files)
2. No engine extraction initially
3. Validate all samples build in VS2022

Then:

4. Introduce engine layer
5. Refactor progressively

---

This approach minimizes risk while maximizing engineering credibility.
