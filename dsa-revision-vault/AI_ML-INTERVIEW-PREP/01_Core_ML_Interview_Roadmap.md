# Core Machine Learning — Interview Roadmap
**For:** Fresher / Campus placements | **Targets:** Big Tech (primary) → AI-startups/labs → Indian product/service companies | **Timeline:** 2–3 months for the FULL journey (ML→DL→CV→LLM→Agentic→SDE)

---

## 0. The Brutal Truth First

- You have 60–90 days for **six** domains. That is tight, not impossible. Core ML should take you **12–14 days** if you go 4–5 hrs/day. If it takes longer, you're over-reading and under-doing.
- **DSA/coding is NOT a separate phase you'll "get to later."** Every single role you listed (including MLE/CV/LLM roles at Big Tech) has a coding round using arrays/strings/trees/graphs/DP. Run **1 DSA problem daily, every single day, starting today**, in parallel with everything else. If you don't, you'll fail the easiest round for the dumbest reason.
- Freshers are **not** expected to derive backprop from raw tensor calculus in every interview — but at Google/Meta/OpenAI-tier and increasingly at good startups, "derive the gradient of X" is a real, common screening question precisely *because* it's fast to ask and instantly separates memorizers from people who understand math.
- Depth code key used below:
  - **[C]** = Conceptual only — explain clearly, no math on paper
  - **[D]** = Derivation — you must be able to write the math on a whiteboard/paper from scratch
  - **[Code]** = You must be able to implement it from scratch in plain Python/NumPy (no sklearn) in ~15–20 min
  - **Priority /10** = likelihood of coming up across your 3 target company tiers, based on aggregated real candidate interview reports (Blind, Exponent, InterviewQuery, GfG, StrataScratch) from 2024–2026.

---

## 1. Math Foundations (Days 1–2) — Don't skip, everything below depends on this

| Topic | Priority | Depth | What exactly to master |
|---|---|---|---|
| Probability basics (Bayes theorem, conditional prob, independence) | 9/10 | [D] | Derive Bayes theorem from first principles; solve conditional probability word problems (classic Amazon/Google favorite) |
| MLE & MAP | 8/10 | [D] | Derive MLE for Bernoulli, Gaussian mean/variance. Know MAP = MLE + prior, connect to regularization |
| Distributions (Gaussian, Bernoulli, Binomial, Poisson) | 7/10 | [C]+[D] | Know PDFs, when each is used, why CLT matters, why Gaussian assumption is used everywhere |
| Hypothesis testing (p-value, t-test, chi-square, A/B testing) | 8/10 | [C] | Heavily asked at product companies (Flipkart/Amazon) for "how would you test if a change improved metric X" |
| Linear Algebra (vectors, matrix mult, eigenvalues/eigenvectors, SVD) | 6/10 | [C]+[D] | Needed to *understand* PCA and backprop, not usually derived standalone. Know eigenvector intuition cold |
| Calculus (partial derivatives, chain rule) | 7/10 | [D] | You WILL be asked to differentiate a loss function on the spot. Practice this until it's reflexive |

---

## 2. Core Supervised Algorithms (Days 3–6) — Highest yield, do not rush

| Algorithm | Priority | Depth | What exactly to master |
|---|---|---|---|
| **Linear Regression** | 10/10 | [D]+[Code] | Derive closed-form (normal equation) via least squares; derive gradient descent update rule; state + explain all assumptions (linearity, homoscedasticity, no multicollinearity, normal residuals); implement from scratch with GD in NumPy |
| **Logistic Regression** | 10/10 | [D]+[Code] | Derive sigmoid from log-odds; derive the log-loss (cross-entropy) via MLE; derive the gradient of the loss w.r.t. weights (asked constantly — practice until automatic); implement from scratch; know softmax for multiclass |
| **Gradient Descent (Batch/SGD/Mini-batch/Momentum/Adam/RMSProp)** | 9/10 | [D]+[Code] | Derive vanilla GD update; explain why SGD is noisy but faster; derive momentum term; know Adam's update rule (even if not deriving fully, know the moving-average intuition); implement plain GD/SGD from scratch |
| **Loss functions (MSE, MAE, Cross-Entropy, Hinge)** | 8/10 | [D] | Derive the gradient of each; know when to use which (MAE robust to outliers, MSE penalizes large errors, why cross-entropy pairs with sigmoid/softmax) |
| **Regularization (L1/L2, Elastic Net)** | 9/10 | [D] | Derive Ridge closed-form solution; explain geometrically why L1 induces sparsity and L2 doesn't (this exact question is a classic — practice drawing the diamond vs circle constraint region); connect to MAP with Laplace/Gaussian priors |
| **Bias-Variance Tradeoff** | 10/10 | [D] | Derive the bias-variance-noise decomposition of expected MSE — this is one of THE most asked theory questions across all tiers, know it cold |
| **Decision Trees (CART, ID3)** | 8/10 | [D]+[Code-lite] | Derive/compute entropy, information gain, Gini impurity by hand on a toy dataset; know how splits are chosen; be ready to code the Gini/entropy calculation, not necessarily the full tree builder |
| **Naive Bayes** | 6/10 | [D] | Derive posterior via Bayes theorem + conditional independence assumption; know Laplace smoothing and why it's needed |
| **K-Nearest Neighbors** | 6/10 | [C]+[Code] | Distance metrics (Euclidean, Manhattan, cosine), curse of dimensionality, why KNN is lazy learning, why feature scaling matters; simple implementation is common |
| **Support Vector Machines** | 7/10 | [D-moderate] | Understand margin maximization and hinge loss derivation at a working level; kernel trick intuition (don't need full dual/KKT derivation unless targeting top-tier — know it exists and why it helps non-linear separability) |

---

## 3. Ensemble Methods (Day 7) — Very hot right now, don't underrate this

| Topic | Priority | Depth | What exactly to master |
|---|---|---|---|
| Bagging & Random Forest | 8/10 | [C]+[D-light] | Why bagging reduces variance (derive intuition via variance of averaged estimators); OOB error; feature importance methods |
| Boosting (AdaBoost, Gradient Boosting) | 9/10 | [D] | Derive the sequential residual-fitting idea of GBM (functional gradient descent); AdaBoost weight update intuition |
| XGBoost / LightGBM / CatBoost | 8/10 | [C] | Know the practical differences (regularization terms in XGBoost objective, leaf-wise vs level-wise growth, how CatBoost handles categoricals) — this comes up a LOT at product companies since it's what's actually used in production |

---

## 4. Unsupervised Learning (Day 8)

| Topic | Priority | Depth | What exactly to master |
|---|---|---|---|
| K-Means Clustering | 8/10 | [D]+[Code] | Derive the objective function (within-cluster SSE minimization) and Lloyd's algorithm steps; implement from scratch (very common coding-round ask); elbow method, silhouette score |
| Hierarchical Clustering, DBSCAN | 5/10 | [C] | Know linkage criteria, when density-based clustering beats K-Means (arbitrary shapes, no need to specify K) |
| PCA | 8/10 | [D]+[Code] | Derive variance-maximization → eigenvector of covariance matrix connection; know the SVD relationship; implement using NumPy eigen decomposition or SVD — this is a favorite for testing real linear algebra understanding |

---

## 5. Model Evaluation & Practical ML (Day 9) — Product companies LOVE this section

| Topic | Priority | Depth | What exactly to master |
|---|---|---|---|
| Confusion Matrix, Precision/Recall/F1 | 10/10 | [C]+formula fluency | Derive each formula, know precision-recall tradeoff, when to optimize for which (fraud detection vs spam) |
| ROC-AUC, PR-AUC | 8/10 | [C] | Know what AUC means geometrically, when PR-AUC is better than ROC-AUC (imbalanced data) |
| Cross-validation (k-fold, stratified, LOOCV) | 8/10 | [C] | Know why stratified matters for imbalanced classes, bias-variance of k choice |
| Overfitting/Underfitting diagnosis | 9/10 | [C] | Learning curves, train-vs-val gap reasoning |
| Handling imbalanced data (SMOTE, class weights, resampling) | 8/10 | [C] | Very common scenario question — "your fraud model has 99% accuracy but is useless, why?" |
| Feature engineering (scaling, encoding, missing values, outliers) | 8/10 | [C]+practical | Standardization vs normalization and WHY (gradient-based models need it, trees don't), one-hot vs target encoding, imputation strategies |
| Concept drift / model monitoring | 6/10 | [C] | Rising fast in 2026 questions — PSI, KS-test, retraining triggers |

---

## 6. Light System Design / Case Studies (Day 10) — Yes, even for freshers now

| Topic | Priority | Depth | What exactly to master |
|---|---|---|---|
| "Design a recommendation system" | 6/10 | [C] | Structure: goal → data → candidate generation → ranking → evaluation. Don't need production-scale depth as fresher, need to show structured thinking |
| "How would you detect fraud/spam?" | 6/10 | [C] | Feature ideas + imbalanced handling + precision/recall tradeoff framing |
| "A model performs well offline but poorly in production, debug it" | 7/10 | [C] | Data leakage, train/serve skew, distribution shift — this is a very common Amazon-style debugging question |

---

## 7. Coding Round Expectations (ongoing, parallel to above)

| What | Priority | Notes |
|---|---|---|
| Implement Linear/Logistic Regression from scratch (NumPy) | 9/10 | Extremely common — practice until you can do it in <15 min without looking anything up |
| Implement K-Means from scratch | 7/10 | Same as above |
| Pandas/NumPy data manipulation | 8/10 | Product companies test this directly — groupby, merge, vectorized ops |
| SQL (joins, window functions, group by) | 7/10 (higher at Flipkart/Amazon-tier) | Non-negotiable for Indian product companies |
| General DSA (arrays, strings, hashmaps, trees, graphs, DP) | 10/10 | This is the actual gatekeeper round at every company tier — don't neglect it while deep in ML theory |

---

## 8. Suggested 12–14 Day Schedule

| Days | Focus |
|---|---|
| 1–2 | Math foundations (Section 1) |
| 3–6 | Core supervised algorithms + derivations + from-scratch code (Section 2) |
| 7 | Ensembles (Section 3) |
| 8 | Unsupervised + PCA (Section 4) |
| 9 | Evaluation metrics + practical ML (Section 5) |
| 10 | Light system design/case studies (Section 6) |
| 11–12 | Mock interviews — explain every derivation out loud, redo from-scratch code without notes |
| 13–14 | Buffer + weakest-topic repair, then move to Deep Learning |

Run 1 DSA problem + review 3–5 flashcard-style concepts from earlier days EVERY day throughout, no exceptions.

---

## 9. How to Actually Practice Derivations (this is where people fake it)

Don't just "read" a derivation. For every [D]-tagged topic:
1. Close the notes.
2. Write the derivation on blank paper from memory, step by step.
3. Compare against source, mark exactly where you got stuck.
4. Redo only that broken step 3x until it's automatic.
5. Explain it out loud in one breath, like you're saying it to an interviewer — if you stumble verbally, you don't actually know it yet.

Next chat, we move to Deep Learning with the same treatment — architectures, backprop derivation, CNN/RNN math, optimizer internals, and what's actually being asked in DL rounds in 2025–2026.
