from pathlib import Path

SRC_DIR = Path("src")

EXTENSIONS = {".cpp", ".hpp"}

total_lines = 0

for file in SRC_DIR.rglob("*"):
    if file.suffix in EXTENSIONS and file.is_file():
        try:
            with open(file, "r", encoding="utf-8", errors="ignore") as f:
                line_count = sum(1 for _ in f)

            total_lines += line_count
            print(f"{file}: {line_count} linii")

        except Exception as e:
            print(f"Błąd przy odczycie {file}: {e}")

print("\n===================")
print(f"Łączna liczba linii: {total_lines}")