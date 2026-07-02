# Day 10 Mistake Analysis

## What went well

Q1 and Q2 were solved within 30 minutes.

## Q3

The missing trigger was:

column choice + adjacent restriction

This is DP, similar to Paint House.

## Q4

Marked red.

The key graph trick is:
An edge is on a shortest path if source-to-one-end + edge-weight + other-end-to-target equals total shortest distance.
