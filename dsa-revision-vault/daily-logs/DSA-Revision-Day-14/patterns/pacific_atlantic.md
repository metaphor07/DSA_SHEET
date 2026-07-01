# Pacific Atlantic Water Flow

Start from ocean borders and move inward.

Movement rule:
```text
neighbor height >= current height
```

Memory hook:
```text
Reverse the flow.
Ocean -> cells that can reach ocean.
```
