# 👨‍🍳 & 🧺 LRU Cache: Custom 🗺️ Map Implementation 🍳✨

## 📝 Ingredients for Your Custom 🗺️ Map

- **`HashMap<Key, Node*>` (The Stickers Cabinet 🗃️)**: An array of buckets 🪣, each points to a linked chain 🔗 of `HashNode`. Choose a prime 🔢 (e.g., 101) for starting bucket count.
- **`HashNode` (Sticker Entry 🎟️)**: Contains:
  - 🔑 `key`
  - 🔁 `ListIterator value` (pointer ➡️ doubly-linked list 🥣)
  - 🔗 `HashNode* next` (for chaining)
- **`hash_func(Key)`**: A fast ⚡ hash function (e.g., rolling 📜 or `std::hash<Key>`) returning `size_t`. Bucket index = `hash_func(key) % capacity`.
- **Load Factor 📈 & Rehashing (Optional “Chef’s Tip” 👨‍🍳)**: When `(size / capacity) > 0.75`, double ➡️🔁 bucket count and rehash to keep lookups 🧐 fast.

---

## 🔪 Kitchen Prep (🗺️ Map Methods)

- **`put(key, ListIterator it)`**:
  1. Compute ➗ `idx = hash_func(key) % capacity`.
  2. Walk 🚶 chain 🔗 at `buckets[idx]`:
     - If `node->key == key`, overwrite ✍️ `node->value = it`, return.
     - Else ➡️, append new `HashNode(key, it)`, increment ⬆️ `size`.
  3. If `size` exceeds 📈 load factor, perform rehashing 🔁.

- **`get(key) → ListIterator | nullptr`**:
  1. Compute ➗ `idx = hash_func(key) % capacity`.
  2. Walk 🚶 `buckets[idx]`:
     - If match 🎯, return `node->value`.
  3. Else 🚫, return `nullptr` (cache miss 🚀).

- **`erase(key)`**:
  1. Compute ➗ `idx = hash_func(key) % capacity`.
  2. Walk 🚶 chain 🔗:
     - On match 🎯, remove ❌ `HashNode`, delete 🗑️, decrement ⬇️ `size`.

---

## 🍽️ Integrating into Your LRU “Chef & Rack”

- Swap 🔄 `std::unordered_map<Key, Iterator>` (**stickers 🎟️**) with your custom `HashMap<Key, Iterator>`.
- Your LRU cache’s methods (`get`, `put`, `move_to_front`, `evict_lru`) stay 💪 same, since your `HashMap` still supports O(1) `get`, `put`, `erase`.
- Rehash 🔁 affects only the sticker cabinet 🗃️; your rack 🧺 (list 🥣) stays intact.

---

## ⚡ Chef’s Sassy Parting Tip 😉

Building 🛠️ your own hash map 🗺️ is like hand-crafting 🛠️ your spice rack 🌶️—totally doable ✅, totally rewarding 🏆. You’ll know every nook 🔍 of your cache kitchen 🍳 and brag 😎 you didn’t use store-bought 🏬 seasoning. Now go cook 👨‍🍳 that custom `HashMap`! 🔥

