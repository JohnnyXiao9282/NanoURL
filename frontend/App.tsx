import Converter from "./Converter/converter";

function App() {
  return (
    <>
      <div
        style={{
          width: "100%",
          height: "80px",
          background: "linear-gradient(to right, #e53935 0%, #1e88e5 100%)",
          boxShadow: "0 4px 12px rgba(0,0,0,0.08)",
          borderBottomLeftRadius: "0",
          borderBottomRightRadius: "0",
          display: "flex",
          alignItems: "center",
          justifyContent: "flex-start",
          fontSize: "2rem",
          color: "#fff",
          fontWeight: "bold",
          letterSpacing: "2px",
          paddingLeft: "24px",
        }}
      >
        NanoURL
      </div>
      <div>
        <Converter />
      </div>
    </>
  );
}

export default App;

// const App: React.FC = () => {
//   const [url, setUrl] = useState('');
//   const [shortUrl, setShortUrl] = useState('');
//   const [error, setError] = useState('');
//   const [copied, setCopied] = useState(false);

//   const handleShorten = async () => {
//     if (!url.trim()) {
//       setError('Please enter a URL.');
//       setShortUrl('');
//       return;
//     }
//     setError('');
//     // TODO: Replace with backend call
//     const mockShort = `https://nano.url/${Math.random().toString(36).substring(2, 8)}`;
//     setShortUrl(mockShort);
//     setCopied(false);
//   };

//   const handleCopy = () => {
//     if (shortUrl) {
//       navigator.clipboard.writeText(shortUrl);
//       setCopied(true);
//       setTimeout(() => setCopied(false), 1200);
//     }
//   };

//   return (
//     <div style={{ minHeight: '100vh', background: '#f4f4f4', margin: 0 }}>
//       <div style={{ background: '#222', color: '#fff', padding: '24px 0', textAlign: 'center', fontSize: '2rem', letterSpacing: '2px', marginBottom: 32 }}>
//         NanoURL
//       </div>
//       <div style={{ display: 'flex', justifyContent: 'center', alignItems: 'center', gap: 8, marginBottom: 24 }}>
//         <input
//           type="text"
//           value={url}
//           onChange={(e: React.ChangeEvent<HTMLInputElement>) => setUrl(e.target.value)}
//           placeholder="Enter your URL here"
//           style={{ padding: 10, fontSize: '1rem', width: 320, border: '1px solid #ccc', borderRadius: 4 }}
//         />
//         <button
//           type="button"
//           onClick={handleShorten}
//           style={{ padding: '10px 18px', fontSize: '1rem', background: '#222', color: '#fff', border: 'none', borderRadius: 4, cursor: 'pointer' }}
//         >
//           Shorten
//         </button>
//       </div>
//       {error && <div style={{ textAlign: 'center', color: 'red', marginBottom: 16 }}>{error}</div>}
//       {shortUrl && (
//         <div style={{ textAlign: 'center', fontSize: '1.1rem', marginTop: 16, color: '#222' }}>
//           Shortened URL: <a href={shortUrl} target="_blank" rel="noopener noreferrer">{shortUrl}</a>
//           <button
//             type="button"
//             onClick={handleCopy}
//             style={{ marginLeft: 12, padding: '6px 14px', fontSize: '1rem', background: '#222', color: '#fff', border: 'none', borderRadius: 4, cursor: 'pointer' }}
//           >
//             {copied ? 'Copied!' : 'Copy'}
//           </button>
//         </div>
//       )}
//     </div>
//   );
// };

// export default App;
